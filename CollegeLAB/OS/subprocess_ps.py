import subprocess

def display_running_processes():
    print("Fetching running processes...\n")
    try:
        result = subprocess.run(
            ['ps', 'aux'], 
            capture_output=True, 
            text=True, 
            check=True
        )
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"Command failed with error: {e}")
    except FileNotFoundError:
        print("The 'ps' command is not available on this system.")

if __name__ == "__main__":
    display_running_processes()
