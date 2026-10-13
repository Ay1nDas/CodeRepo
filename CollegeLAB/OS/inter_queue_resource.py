def inter_queue_slicing(high_procs, low_procs, high_slice=4, low_slice=2):
    time, schedule = 0, []
    h_rem = {p["pid"]: p["bt"] for p in high_procs}
    l_rem = {p["pid"]: p["bt"] for p in low_procs}
    
    while any(h_rem[p] > 0 for p in h_rem) or any(l_rem[p] > 0 for p in l_rem):
        # High Priority Queue Execution
        for p in high_procs:
            if h_rem[p["pid"]] > 0:
                run = min(high_slice, h_rem[p["pid"]])
                time += run; h_rem[p["pid"]] -= run
                schedule.append((p["pid"], run))
        # Low Priority Queue Execution
        for p in low_procs:
            if l_rem[p["pid"]] > 0:
                run = min(low_slice, l_rem[p["pid"]])
                time += run; l_rem[p["pid"]] -= run
                schedule.append((p["pid"], run))
                
    return schedule

print(inter_queue_slicing([{"pid": "H1", "bt": 8}], [{"pid": "L1", "bt": 4}]))
