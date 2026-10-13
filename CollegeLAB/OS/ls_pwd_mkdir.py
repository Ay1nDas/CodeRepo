import os

def simulate_pwd():
    print(os.getcwd())

def simulate_ls(path='.'):
    try:
        files = os.listdir(path)
        for item in files:
            print(item, end='  ')
        print()
    except FileNotFoundError:
        print(f"ls: cannot access '{path}': No such file or directory")

def simulate_mkdir(dir_name):
    try:
        os.mkdir(dir_name)
        print(f"Directory '{dir_name}' created successfully.")
    except FileExistsError:
        print(f"mkdir: cannot create directory '{dir_name}': File exists")

if __name__ == "__main__":
    print("--- pwd ---")
    simulate_pwd()
    
    print("\n--- ls ---")
    simulate_ls()
    
    print("\n--- mkdir test_dir ---")
    simulate_mkdir("test_dir")
