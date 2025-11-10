#include <iostream>
#include <vector>
#include <algorithm> // For sort, find, lower_bound, etc.
#include <string>    // For vector<string> example
using namespace std;

int main()
{
  // === Constructors ===
  vector<int> v1;                             // Empty vector
  vector<int> v2(5);                          // 5 elements, all initialized to 0
  vector<int> v3(5, 10);                      // 5 elements, all initialized to 10
  vector<int> v4 = {1, 2, 3, 4, 5};           // From initializer list
  vector<int> v5 = v4;                        // Copy constructor
  vector<int> v6(v4.begin(), v4.begin() + 3); // Copy range [1, 2, 3]

  // === Capacity ===
  v3.size();        // Returns size (5). return type: size_t. Complexity: O(1)
  v1.empty();       // true.             return type: bool. Complexity: O(1)
  v3.clear();       // Empties v3.       return type: void. Complexity: O(N)
  v1.resize(10);    // Resizes v1 to 10 elements (value 0). Complexity: O(N)
  v1.resize(12, 7); // Resizes v1 to 12, new elements are 7. Complexity: O(N)
  v1.capacity();    // Returns allocated storage. return type: size_t. Complexity: O(1)
  v1.reserve(20);   // Allocates space for at least 20 elements. Complexity: O(N)

  // === Element Access ===
  v4[0];          // 1. NO bounds checking.     return type: reference(int&). Complexity: O(1)
  v4.at(1);       // 2. Performs bounds checking. return type: reference(int&). Complexity: O(1)
  v4.front();     // 1. Get first char.         return type: reference(int&). Complexity: O(1)
  v4.back();      // 5. Get last char.          return type: reference(int&). Complexity: O(1)
  v4.back() = 99; // Modifies last element. v4 is now {1, 2, 3, 4, 99}

  // === Modifiers ===
  v1.push_back(5); // Appends 5.          return type: void. Complexity: O(1) amortized
  v1.pop_back();   // Removes last element. return type: void. Complexity: O(1)

  // Inserts 8 at index 2. Needs iterator.
  // Complexity: O(N)
  v4.insert(v4.begin() + 2, 8); // v4 is {1, 2, 8, 3, 4, 99}

  // Inserts 3 copies of 7 at index 1.
  // Complexity: O(N)
  v4.insert(v4.begin() + 1, 3, 7); // v4 is {1, 7, 7, 7, 2, 8, 3, 4, 99}

  // Erases element at index 2 (value 7).
  // Complexity: O(N)
  v4.erase(v4.begin() + 2);

  // Erases range [index 2, index 4)
  // Complexity: O(N)
  v4.erase(v4.begin() + 2, v4.begin() + 4);

  v1.swap(v4); // Swaps contents of v1 and v4. Complexity: O(1)

  // === Iterators ===
  v4.begin();  // Iterator to first element.  return type: iterator
  v4.end();    // Iterator to *after* last element. return type: iterator
  v4.rbegin(); // Reverse iterator to last element. return type: reverse_iterator
  v4.rend();   // Reverse iterator to *before* first element. return type: reverse_iterator

  // Example: Iterate and print
  for (int i = 0; i < v4.size(); ++i)
  {
    // cout << v4[i] << " ";
  }
  // Example: Range-based for loop (C++11)
  for (int x : v4)
  {
    // cout << x << " ";
  }
  // Example: Iterate with iterators
  for (auto it = v4.begin(); it != v4.end(); ++it)
  {
    // cout << *it << " ";
  }

  // === Algorithms (requires <algorithm>) ===
  // Sorts the vector.
  // Complexity: O(N log N)
  sort(v4.begin(), v4.end());

  // Sorts in descending order.
  // Complexity: O(N log N)
  sort(v4.begin(), v4.end(), greater<int>());

  // Reverses the vector.
  // Complexity: O(N)
  reverse(v4.begin(), v4.end());

  // Finds element 3. Returns iterator.
  // Complexity: O(N)
  auto it = find(v4.begin(), v4.end(), 3);
  if (it != v4.end())
  {
    // found
  }

  // --- Must be sorted for these ---
  sort(v4.begin(), v4.end());

  // Finds iterator to first element >= 3.
  // Complexity: O(log N)
  auto it_lower = lower_bound(v4.begin(), v4.end(), 3);

  // Finds iterator to first element > 3.
  // Complexity: O(log N)
  auto it_upper = upper_bound(v4.begin(), v4.end(), 3);

  return 0;
}