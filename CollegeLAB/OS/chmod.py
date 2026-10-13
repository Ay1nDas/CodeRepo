import os
import stat

def view_permissions(filename):
    """View file permissions in octal format."""
    try:
        file_stat = os.stat(filename)
        mode = oct(stat.S_IMODE(file_stat.st_mode))
        print(f"Permissions for '{filename}': {mode}")
    except FileNotFoundError:
        print(f"File '{filename}' not found.")

def modify_permissions(filename, octal_mode):
    """Modify file permissions."""
    try:
        os.chmod(filename, octal_mode)
        print(f"Successfully changed permissions of '{filename}' to {oct(octal_mode)}")
    except FileNotFoundError:
        print(f"File '{filename}' not found.")
    except PermissionError:
        print(f"Permission denied to change '{filename}'")

if __name__ == "__main__":
    test_file = "perm_test.txt"
    with open(test_file, 'w') as f:
        f.write("Test")

    print("Initial Permissions:")
    view_permissions(test_file)
    
    print("\nModifying to 0o755 (rwxr-xr-x)...")
    modify_permissions(test_file, 0o755)
    
    print("\nUpdated Permissions:")
    view_permissions(test_file)
