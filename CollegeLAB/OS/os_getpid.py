import os

def main():
    pid = os.fork()

    if pid > 0:
        print(f"[Parent] PID: {os.getpid()}, Parent PID (PPID): {os.getppid()}")
    elif pid == 0:
        print(f"[Child]  PID: {os.getpid()}, Parent PID (PPID): {os.getppid()}")

if __name__ == "__main__":
    main()
