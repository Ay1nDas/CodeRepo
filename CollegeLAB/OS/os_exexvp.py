import os

def main():
    print("Replacing current process with 'ls -l' command...")
    # execvp(file, args)
    # The first argument in the list is by convention the executable name
    os.execvp("ls", ["ls", "-l"])
    
    # This line will never execute if execvp is successful
    print("This will not be printed if execvp succeeds.")

if __name__ == "__main__":
    main()
