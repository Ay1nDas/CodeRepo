
cmake_minimum_required(VERSION 3.20)
project(CJIT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Using LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM directory: ${LLVM_DIR}")

include_directories(SYSTEM ${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(c-jit src/main.cpp)

llvm_map_components_to_libnames(LLVM_LIBS
    Core
    IRReader
    Support
    OrcJIT
    ExecutionEngine
    RuntimeDyld
    Object
    native
)

target_link_libraries(c-jit PRIVATE ${LLVM_LIBS} ${CMAKE_DL_LIBS})

# Export executable symbols for JIT symbol resolution.
set_target_properties(c-jit PROPERTIES ENABLE_EXPORTS ON)
