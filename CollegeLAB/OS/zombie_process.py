import os
import time

def main():
    pid = os.fork()

    if pid == 0:
        print(f"[Child] PID: {os.getpid()} exiting...")
        os._exit(0)
    else:
        print(f"[Parent] PID: {os.getpid()} sleeping. Check 'ps aux | grep {pid}' in another terminal to see Zombie [Z+] status.")
        time.sleep(10)  # Keeps parent alive without calling os.wait()
        os.wait()      # Cleans up zombie process after sleep
        print("[Parent] Cleaned up child exit status.")

if __name__ == "__main__":
    main()
