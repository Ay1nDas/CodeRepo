import matplotlib.pyplot as plt\

schedule = [
  ("P1",0,5), ("P2",5,8),
  ("P3",8,10), ("P4",10,14)
]

fig, ax = plt.subplots(figsize=(9,2.5))

for pid, start, end in schedule:
    ax.barh(0, end-start, left=start,
      height=0.45, edgecolor="black")
    ax.text((start+end)/2, 0, pid,
      ha="center", va="center")

ax.set_yticks([])
ax.set_xlabel("Time")
ax.set_title("CPU Scheduling - Gantt Chart")
ax.set_xlim(0,14)
ax.grid(axis="x", linestyle="--", alpha=0.4)
plt.tight_layout()
plt.show()