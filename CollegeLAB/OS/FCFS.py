def fcfs(processes):
    time = 0
    for p in sorted(processes, key=lambda x: x["at"]):
        time = max(time, p["at"])
        p["ct"] = time + p["bt"]
        p["tat"], p["wt"] = p["ct"] - p["at"], p["ct"] - p["at"] - p["bt"]
        time = p["ct"]
    return processes

procs = [{"pid": "P1", "at": 0, "bt": 5}, {"pid": "P2", "at": 1, "bt": 3}]
print(fcfs(procs))