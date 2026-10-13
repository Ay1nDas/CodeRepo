get_fib() {
    local target=$1
    local a=0
    local b=1
    if [ $target -le 0 ]; then echo 0; return; fi
    if [ $target -eq 1 ]; then echo 1; return; fi
    for (( i=2; i<=target; i++ )); do
        fn=$((a + b))
        a=$b
        b=$fn
    done
    echo $b
}
for val in "$@"; do
    echo "F($val) = $(get_fib $val)"
done
