import os

def read_process_status(pid):
    status_path = f"/proc/{pid}/status"
    
    if not os.path.exists(status_path):
        print(f"Process {pid} does not exist.")
        return

    print(f"--- Process Status for PID {pid} ---")
    with open(status_path, "r") as file:
        for line in file:
            # Display primary status lines
            if any(line.startswith(key) for key in ["Name:", "State:", "Pid:", "PPid:", "VmSize:"]):
                print(line.strip())

if __name__ == "__main__":
    current_pid = os.getpid()
    read_process_status(current_pid)
