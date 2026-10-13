import os

def list_files_categorized(path='.'):
    try:
        all_files = os.listdir(path)

        hidden_files = [f for f in all_files if f.startswith('.')]
        regular_files = [f for f in all_files if not f.startswith('.')]
        
        print("Regular Files:")
        for f in regular_files:
            print(f"  {f}")
            
        print("\nHidden Files:")
        for f in hidden_files:
            print(f"  {f}")
            
    except FileNotFoundError:
        print(f"Directory '{path}' not found.")

if __name__ == "__main__":
    list_files_categorized()
