import multiprocessing
import time

def daemon_task():
    print("[Daemon Process] Started running in background...")
    time.sleep(5)
    print("[Daemon Process] Finished task.")

if __name__ == "__main__":
    p = multiprocessing.Process(target=daemon_task)
    p.daemon = True  # Set as daemon before starting
    p.start()

    print("[Main Process] Main execution finishing...")
    time.sleep(1)
    print("[Main Process] Exiting. Daemon process will terminate automatically.")
