echo "Total Arguments: $#"
echo "Using FOR loop:"
for arg in "$@"; do
    echo "  Arg: $arg"
done

echo "Using WHILE loop (Countdown):"
count=$#
while [ $count -gt 0 ]; do
    echo "  Remaining: $count"
    count=$((count - 1))
done
