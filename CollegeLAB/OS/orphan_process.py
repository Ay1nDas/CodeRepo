import os
import time

def main():
    pid = os.fork()

    if pid > 0:
        print(f"[Parent] PID: {os.getpid()} exiting immediately...")
        os._exit(0)
    elif pid == 0:
        print(f"[Child]  Initial PPID: {os.getppid()}")
        time.sleep(2)  # Wait for parent to terminate
        print(f"[Child]  Orphaned! New PPID (Init process): {os.getppid()}")

if __name__ == "__main__":
    main()
