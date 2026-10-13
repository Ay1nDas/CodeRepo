echo -e "1. Add\n2. Sub\n3. Mul\n4. Div"
read -p "Select choice (1-4): " choice
read -p "Enter a: " a
read -p "Enter b: " b

case $choice in
    1) echo "Result: $((a + b))" ;;
    2) echo "Result: $((a - b))" ;;
    3) echo "Result: $((a * b))" ;;
    4) echo "Result: $((a / b))" ;;
    *) echo "Invalid" ;;
esac
