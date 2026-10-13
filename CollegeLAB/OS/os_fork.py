import os

def main():
    pid = os.fork()
    
    if pid > 0:
        print(f"[Parent Process] Created child with PID: {pid}")
    elif pid == 0:
        print(f"[Child Process] Running independently.")
    else:
        print("Fork failed!")

if __name__ == "__main__":
    main()
