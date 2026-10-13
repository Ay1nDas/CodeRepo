def mlq_with_aging(high_q, low_q, max_wait=5):
    time = 0
    while high_q or low_q:
        # Age low priority processes
        promoted = [p for p in low_q if (time - p["at"]) >= max_wait]
        for p in promoted:
            print(f"[Aging] Promoted {p['pid']} to High Queue at time {time}")
            low_q.remove(p); high_q.append(p)
            
        curr = high_q.pop(0) if high_q else low_q.pop(0)
        time = max(time, curr["at"]) + curr["bt"]
        curr["ct"] = time
        print(f"Executed {curr['pid']} | Finished: {time}")

mlq_with_aging([{"pid": "H1", "at": 0, "bt": 4}], [{"pid": "L1", "at": 0, "bt": 2}])
