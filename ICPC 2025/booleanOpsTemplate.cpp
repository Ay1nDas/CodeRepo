#include <iostream>
#include <bitset> // For printing binary representations
using namespace std;

// Helper function to print binary
template <typename T>
void printBinary(const string &title, T val)
{
  // bitset<8> will show 8 bits, good for chars and small ints
  // For general ints, use bitset<sizeof(T) * 8>
  cout << title << ": " << bitset<8>(val) << " (" << val << ")" << endl;
}

int main()
{
  // === 1. Standard Boolean Operations (&&, ||, !) ===
  // These operate on 'bool' types (true/false).
  // They use "short-circuiting".
  cout << "--- Standard Boolean Ops ---" << endl;

  bool a = true;
  bool b = false;

  // Logical AND (&&): true only if *both* are true.
  cout << "a && b: " << (a && b) << endl;       // false
  cout << "a && true: " << (a && true) << endl; // true

  // Logical OR (||): true if *at least one* is true.
  cout << "a || b: " << (a || b) << endl;         // true
  cout << "b || false: " << (b || false) << endl; // false

  // Logical NOT (!): inverts the value.
  cout << "!a: " << (!a) << endl; // false
  cout << "!b: " << (!b) << endl; // true

  // --- 2. Bitwise Operations (&, |, ^, ~, <<, >>) ---
  // These operate on the individual *bits* of integer types (int, char, long long).
  // They do *not* short-circuit.

  cout << "\n--- Bitwise Ops ---" << endl;
  // Let x = 5  (Binary: 00000101)
  // Let y = 3  (Binary: 00000011)
  int x = 5;
  int y = 3;

  printBinary("x", x);
  printBinary("y", y);

  // Bitwise AND (&): Sets a bit to 1 only if *both* corresponding bits are 1.
  //   00000101 (5)
  // & 00000011 (3)
  //   --------
  //   00000001 (1)
  printBinary("x & y", (x & y));

  // Bitwise OR (|): Sets a bit to 1 if *at least one* corresponding bit is 1.
  //   00000101 (5)
  // | 00000011 (3)
  //   --------
  //   00000111 (7)
  printBinary("x | y", (x | y));

  // Bitwise XOR (^): Sets a bit to 1 if the corresponding bits are *different*.
  //   00000101 (5)
  // ^ 00000011 (3)
  //   --------
  //   00000110 (6)
  printBinary("x ^ y", (x ^ y));

  // Bitwise NOT (~): Flips every bit (0 -> 1, 1 -> 0).
  // (This is a 1's complement. Result depends on type, e.g., 32-bits for int)
  // ~ 00000101 (5)
  //   --------
  //   11111010 (-6 in 2's complement)
  printBinary("~x", (~x));

  // Bitwise Left Shift (<<): Shifts bits to the left, fills with 0s.
  // Equivalent to multiplying by 2^N.
  // 00000101 (5) << 1  ->  00001010 (10)
  printBinary("x << 1", (x << 1));

  // Bitwise Right Shift (>>): Shifts bits to the right.
  // For unsigned types, fills with 0s (logical shift).
  // For signed types (like int), may fill with sign bit (arithmetic shift).
  // Equivalent to dividing by 2^N (integer division).
  // 00000101 (5) >> 1  ->  00000010 (2)
  printBinary("x >> 1", (x >> 1));

  // === 3. Common Bit Manipulation Tricks (for ICPC) ===
  cout << "\n--- Bit Manipulation Tricks ---" << endl;
  int n = 24; // 00011000
  int k = 3;  // Check, set, clear, toggle the 3rd bit (0-indexed)

  // A "mask" is a value used to target specific bits.
  // To target the k-th bit, use (1 << k)
  int mask = (1 << k); // 1 << 3  ->  00001000 (8)
  printBinary("n", n);
  printBinary("mask (1 << k)", mask);

  // Check if k-th bit is set (is 1)
  //   00011000 (n)
  // & 00001000 (mask)
  //   --------
  //   00001000 (non-zero, so it's set)
  bool isKthBitSet = (n & mask) != 0;
  cout << "Is 3rd bit set? " << (isKthBitSet ? "true" : "false") << endl; // true

  // Set k-th bit (to 1)
  //   00011000 (n)
  // | 00001000 (mask)
  //   --------
  //   00011000 (24)
  printBinary("Set 3rd bit", (n | mask));

  // Clear k-th bit (to 0)
  // Use the inverse of the mask (~mask)
  // ~mask = 11110111
  //   00011000 (n)
  // & 11110111 (~mask)
  //   --------
  //   00010000 (16)
  printBinary("Clear 3rd bit", (n & (~mask)));

  // Toggle k-th bit (1->0, 0->1)
  //   00011000 (n)
  // ^ 00001000 (mask)
  //   --------
  //   00010000 (16)
  printBinary("Toggle 3rd bit", (n ^ mask));

  // Get lowest set bit (LSB)
  //   n = 24 (00011000)
  //  -n = -24 (11101000) (in 2's complement)
  // n & (-n) = 00001000 (8)
  printBinary("Lowest set bit (n & -n)", (n & (-n)));

  // Clear lowest set bit (e.g., to iterate through set bits)
  //   n = 24 (00011000)
  // n-1 = 23 (00010111)
  // n & (n-1) = 00010000 (16)
  printBinary("Clear lowest set bit (n & (n-1))", (n & (n - 1)));

  return 0;
}