# metrics.py

class Process:
    def __init__(self, pid, arrival_time, burst_time, priority=0):
        self.pid = pid
        self.at = arrival_time
        self.bt = burst_time
        self.priority = priority
        
        # Computed fields
        self.ct = 0   # Completion Time
        self.tat = 0  # Turnaround Time (CT - AT)
        self.wt = 0   # Waiting Time (TAT - BT)
        self.remaining_bt = burst_time  # Used for preemptive/Round Robin algorithms


def calculate_metrics(processes):
    """Calculates TAT and WT for each process given its CT."""
    for p in processes:
        p.tat = p.ct - p.at
        p.wt = p.tat - p.bt


def display_results(processes, title="CPU Scheduling Results"):
    """Displays a formatted table of process execution details and average metrics."""
    calculate_metrics(processes)
    
    print(f"\n{'=' * 65}")
    print(f" {title.center(63)} ")
    print(f"{'=' * 65}")
    print(f"{'PID':<6}{'Arrival':<10}{'Burst':<8}{'Priority':<10}{'CT':<8}{'TAT':<8}{'WT':<8}")
    print("-" * 65)
    
    total_tat = 0
    total_wt = 0
    
    for p in sorted(processes, key=lambda x: x.pid):
        print(f"P{p.pid:<5}{p.at:<10}{p.bt:<8}{p.priority:<10}{p.ct:<8}{p.tat:<8}{p.wt:<8}")
        total_tat += p.tat
        total_wt += p.wt
        
    n = len(processes)
    print("-" * 65)
    print(f"Average Turnaround Time (TAT) : {total_tat / n:.2f}")
    print(f"Average Waiting Time (WT)    : {total_wt / n:.2f}")
    print(f"{'=' * 65}\n")