from collections import deque

def round_robin(processes, q):
    rem = {p["pid"]: p["bt"] for p in processes}
    ct, queue, arrived, time = {}, deque(), set(), 0
    while len(ct) < len(processes):
        for p in processes:
            if p["at"] <= time and p["pid"] not in arrived:
                queue.append(p["pid"]); arrived.add(p["pid"])
        if not queue:
            time = min(p["at"] for p in processes if p["pid"] not in arrived); continue
        pid = queue.popleft()
        run = min(q, rem[pid])
        time += run; rem[pid] -= run
        for p in processes:
            if p["at"] <= time and p["pid"] not in arrived:
                queue.append(p["pid"]); arrived.add(p["pid"])
        if rem[pid] > 0: queue.append(pid)
        else: ct[pid] = time
    for p in processes:
        p["ct"] = ct[p["pid"]]
        p["tat"], p["wt"] = p["ct"] - p["at"], p["ct"] - p["at"] - p["bt"]
    return processes

procs = [{"pid": "P1", "at": 0, "bt": 5}, {"pid": "P2", "at": 0, "bt": 4}]
print(round_robin(procs, 2))
