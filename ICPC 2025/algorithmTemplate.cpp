#include <iostream>
#include <vector>
#include <algorithm> // For sort, min_element, etc.
#include <numeric>   // For accumulate, iota
#include <string>
using namespace std;

// === 1. Simple Comparison Function (bool) ===
// Used for custom sort.
// Returns 'true' if 'a' should come *before* 'b'.
bool compareDescending(int a, int b)
{
  return a > b; // For descending, return a > b
}
// === 2. Comparator Struct (Functor) ===
// Used for custom sort.
struct MyStruct
{
  int id;
  int value;
  // Overloading < operator (METHOD 1 for sorting structs)
  // This defines the "natural" order for MyStruct.
  // 'const' is important.
  bool operator<(const MyStruct &other) const
  {
    // Sort by 'value' ascending.
    // If values are equal, sort by 'id' ascending.
    if (value != other.value)
    {
      return value < other.value;
    }
    return id < other.id;
  }
};
// Custom comparator struct (METHOD 2 for sorting structs)
// This allows for *alternative* orderings.
struct CompareStructByValueDesc
{
  bool operator()(const MyStruct &a, const MyStruct &b) const
  {
    return a.value > b.value;
  }
};

int main()
{
  vector<int> v = {5, 2, 8, 1, 9, 4};
  // === Common Algorithms ===
  cout << "--- Algorithms ---" << endl;
  cout << "min(10, 20): " << min(10, 20) << endl; // 10
  cout << "max(10, 20): " << max(10, 20) << endl; // 20

  // Find iterator to min/max element in a range
  auto it_min = min_element(v.begin(), v.end());
  cout << "Min element: " << *it_min << endl; // 1
  auto it_max = max_element(v.begin(), v.end());
  cout << "Max element: " << *it_max << endl; // 9
  // Sum of elements (from <numeric>)
  // 0 is the initial value
  int sum = accumulate(v.begin(), v.end(), 0);
  cout << "Sum: " << sum << endl; // 29
  // Fill vector with 0, 1, 2, 3, 4, 5 (from <numeric>)
  vector<int> v_iota(6);
  iota(v_iota.begin(), v_iota.end(), 0); // Fills with 0, 1, 2, 3, 4, 5

  // === Sorting (The most important part) ===
  cout << "\n--- Sorting ---" << endl;

  // 1. Standard Sort (Ascending)
  // Complexity: O(N log N)
  sort(v.begin(), v.end()); // v = {1, 2, 4, 5, 8, 9}
  // 2. Binary Search (ONLY works on a sorted range)
  // Complexity: O(log N)
  bool found = binary_search(v.begin(), v.end(), 4);
  cout << "Found 4? " << found << endl; // true
  // 3. Sort Descending (using std::greater)
  sort(v.begin(), v.end(), greater<int>()); // v = {9, 8, 5, 4, 2, 1}
  // 4. Sort Descending (using a boolean function)
  sort(v.begin(), v.end(), compareDescending); // v = {9, 8, 5, 4, 2, 1}
  // 5. Sort using a C++11 Lambda (Most flexible method)
  // Sorts ascending by absolute value
  vector<int> v_abs = {-10, 5, -2, 1};
  sort(v_abs.begin(), v_abs.end(), [](int a, int b)
       {
         return abs(a) < abs(b); // v_abs = {1, -2, 5, -10}
       });

  // === Sorting Structs/Pairs ===
  cout << "\n--- Sorting Structs ---" << endl;
  vector<MyStruct> s_vec = {{1, 100}, {2, 50}, {3, 50}};
  // 6. Sort struct using its overloaded < operator
  sort(s_vec.begin(), s_vec.end());
  // s_vec = {{2, 50}, {3, 50}, {1, 100}} (sorted by value, then id)
  // 7. Sort struct using a comparator struct
  sort(s_vec.begin(), s_vec.end(), CompareStructByValueDesc());
  // s_vec = {{1, 100}, {2, 50}, {3, 50}} (sorted by value descending)

  // === Permutations ===
  cout << "\n--- Permutations ---" << endl;
  string s = "abc";
  // Iterates through all unique permutations in lexicographical order.
  // Start with the string sorted for this to work correctly.
  do
  {
    // cout << s << endl; // abc, acb, bac, bca, cab, cba
  } while (next_permutation(s.begin(), s.end()));

  return 0;
}