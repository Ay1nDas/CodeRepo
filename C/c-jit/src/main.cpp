
#include <iostream>
#include <memory>

// #include "llvm/ADT/Optional.h"
#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/ExecutionEngine/Orc/ExecutionUtils.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/Error.h"

using namespace llvm;
using namespace llvm::orc;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: c-jit <input.ll>\n";
        return 1;
    }

    // Initialize the native target for JIT compilation.
    if (InitializeNativeTarget() ||
        InitializeNativeTargetAsmPrinter()) {
        std::cerr << "Failed to initialize native target\n";
        return 1;
    }

    ExitOnError ExitOnErr;

    // Create an LLVM ORC JIT engine.
    auto JIT = ExitOnErr(LLJITBuilder().create());

    // Allow JIT-compiled code to resolve functions such as printf.
    auto Generator = ExitOnErr(
        DynamicLibrarySearchGenerator::GetForCurrentProcess(
            JIT->getDataLayout().getGlobalPrefix()));

    JIT->getMainJITDylib().addGenerator(std::move(Generator));

    // Create a context and parse the LLVM IR file.
    auto Context = std::make_unique<LLVMContext>();

    SMDiagnostic Error;
    auto ModuleIR = parseIRFile(argv[1], Error, *Context);

    if (!ModuleIR) {
        Error.print(argv[0], errs());
        return 1;
    }

    // Match the module to the JIT's target configuration.
    ModuleIR->setDataLayout(JIT->getDataLayout());
    ModuleIR->setTargetTriple(JIT->getTargetTriple());

    // Transfer the module to the JIT.
    ExitOnErr(JIT->addIRModule(
        ThreadSafeModule(
            std::move(ModuleIR),
            ThreadSafeContext(std::move(Context)))));

    // Find the compiled main() function.
    auto MainSymbol = ExitOnErr(JIT->lookup("main"));

    // Our example uses int main(), with no arguments.
    auto Main = MainSymbol.toPtr<int (*)()>();

    std::cout << "Executing C program...\n";

    int result = Main();

    std::cout << "main() returned: " << result << '\n';

    return 0;
}
