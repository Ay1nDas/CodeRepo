from collections import deque

def mlq_two_level(sys_procs, user_procs, q=2):
    time, sys_q, user_q = 0, deque(sorted(sys_procs, key=lambda x: x["at"])), deque()
    rem_user = {p["pid"]: p["bt"] for p in user_procs}
    
    # Process System Queue (FCFS) first
    while sys_q:
        p = sys_q.popleft()
        time = max(time, p["at"]) + p["bt"]
        p["ct"] = time
        
    # Process User Queue (Round Robin)
    user_arrived = sorted(user_procs, key=lambda x: x["at"])
    while any(rem_user[p] > 0 for p in rem_user):
        for p in user_arrived:
            if p["at"] <= time and p["pid"] not in [x["pid"] for x in user_q] and rem_user[p["pid"]] > 0:
                user_q.append(p)
        if not user_q:
            time += 1; continue
        curr = user_q.popleft()
        run = min(q, rem_user[curr["pid"]])
        time += run; rem_user[curr["pid"]] -= run
        if rem_user[curr["pid"]] == 0: curr["ct"] = time
        else: user_q.append(curr)
        
    return sys_procs + user_procs

sys_p = [{"pid": "S1", "at": 0, "bt": 3}]
user_p = [{"pid": "U1", "at": 0, "bt": 4}]
print(mlq_two_level(sys_p, user_p))
