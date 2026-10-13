import os
import time

def main():
    pid = os.fork()

    if pid == 0:
        print("[Child] Working...")
        time.sleep(2)
        print("[Child] Exiting with status code 0.")
        os._exit(0)  # Exits child process immediately
    else:
        print("[Parent] Waiting for child to finish...")
        child_pid, status = os.wait()
        print(f"[Parent] Child with PID {child_pid} terminated with status: {status}")

if __name__ == "__main__":
    main()
