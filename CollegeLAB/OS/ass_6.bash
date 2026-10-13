#!/bin/bash
# Native Bash CPU stress tool (4 infinite loops)

pids=()

for i in {1..4}; do
    # Pure CPU loop reading null device
    sha256sum /dev/urandom > /dev/null 2>&1 &
    pids+=($!)
done

echo "CPU stress started."
echo "PIDs: ${pids[*]}"
echo "Run 'kill ${pids[*]}' or 'killall sha256sum' to stop."


# #!/bin/bash
# # Allocate 1GB in RAM filesystem to simulate memory spike
# mkdir -p /dev/shm/ram_test
# dd if=/dev/zero of=/dev/shm/ram_test/fill bs=1M count=1024
# echo "1GB RAM allocated in /dev/shm"
