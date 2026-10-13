def simulate_grep(pattern, filename):
    """Simulates 'grep pattern filename'"""
    try:
        with open(filename, 'r') as file:
            for line in file:
                if pattern in line:
                    print(line, end='')
    except FileNotFoundError:
        print(f"grep: {filename}: No such file or directory")

def simulate_wc(filename):
    """Simulates 'wc filename' (outputs lines, words, chars)"""
    try:
        with open(filename, 'r') as file:
            text = file.read()
            lines = text.count('\n')
            words = len(text.split())
            chars = len(text)
            
            print(f" {lines} {words} {chars} {filename}")
    except FileNotFoundError:
        print(f"wc: {filename}: No such file or directory")

if __name__ == "__main__":
    test_file = "sample.txt"
    with open(test_file, 'w') as f:
        f.write("Hello World\nThis is a test file.\nTesting grep and wc.\n")
    
    print("--- grep 'test' sample.txt ---")
    simulate_grep("test", test_file)
    
    print("\n--- wc sample.txt ---")
    simulate_wc(test_file)
