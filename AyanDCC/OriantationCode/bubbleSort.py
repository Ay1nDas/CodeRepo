"""
Implements the Bubble Sort algorithm.

This module provides a function to sort a list in ascending order
using the Bubble Sort method. It can be run as a standalone script
to see an example of the sorting in action.
"""


def bubble_sort(data):
    n = len(data)

    for i in range(n):
        swapped = False

        for j in range(0, n - i - 1):

            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
                swapped = True

        if not swapped:
            break


# Example usage:
if __name__ == "__main__":
    # Use a different variable name ('numbers') to avoid linter warnings
    numbers = [64, 34, 25, 12, 22, 11, 90]

    print(f"Unsorted array: {numbers}")

    # Pass the 'numbers' list to the function
    bubble_sort(numbers)

    print(f"Sorted array:   {numbers}")
