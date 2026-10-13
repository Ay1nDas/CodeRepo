def sjf(processes):
    rem, time, res = processes[:], 0, []
    while rem:
        ready = [p for p in rem if p["at"] <= time]
        if not ready:
            time = min(p["at"] for p in rem); continue
        p = min(ready, key=lambda x: (x["bt"], x["at"]))
        rem.remove(p)
        p["ct"] = time + p["bt"]
        p["tat"], p["wt"] = p["ct"] - p["at"], p["ct"] - p["at"] - p["bt"]
        time = p["ct"]
        res.append(p)
    return res

procs = [{"pid": "P1", "at": 0, "bt": 7}, {"pid": "P2", "at": 1, "bt": 4}]
print(sjf(procs))
