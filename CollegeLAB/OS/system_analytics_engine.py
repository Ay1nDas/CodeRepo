def system_analytics(processes, total_time, context_switches):
    n = len(processes)
    for p in processes:
        p["tat"] = p["ct"] - p["at"]
        p["wt"] = p["tat"] - p["bt"]
        p["response_time"] = p["start_time"] - p["at"]
        
    avg_resp = sum(p["response_time"] for p in processes) / n
    throughput = n / total_time
    
    print(f"Avg Response Time : {avg_resp:.2f}")
    print(f"System Throughput : {throughput:.2f} proc/unit time")
    print(f"Context Switches  : {context_switches}")

procs = [{"pid": "P1", "at": 0, "bt": 5, "start_time": 0, "ct": 5}]
system_analytics(procs, total_time=5, context_switches=1)
