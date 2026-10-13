def compute_metrics(processes):
    for p in processes:
        p["tat"] = p["ct"] - p["at"]  # TAT = CT - AT
        p["wt"] = p["tat"] - p["bt"]  # WT = TAT - BT
    avg_tat = sum(p["tat"] for p in processes) / len(processes)
    avg_wt = sum(p["wt"] for p in processes) / len(processes)
    return avg_tat, avg_wt

processes = [{"pid": "P1", "at": 0, "bt": 5, "ct": 5}, {"pid": "P2", "at": 1, "bt": 3, "ct": 8}]
avg_tat, avg_wt = compute_metrics(processes)
print(processes, f"\nAvg TAT: {avg_tat}, Avg WT: {avg_wt}")
