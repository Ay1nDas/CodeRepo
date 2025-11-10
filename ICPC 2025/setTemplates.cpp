#include <iostream>
#include <set>
#include <string>
using namespace std;

// std::set is an ordered set (Red-Black Tree).
// Stores *unique* keys in sorted order.
// All operations (insert, erase, find) are O(log N).
//
// For unique unsorted keys (O(1) avg), use std::unordered_set.

int main()
{
  // === Constructors ===
  set<int> s1;                      // Empty set
  set<int> s2 = {1, 5, 3, 2, 5, 1}; // From initializer list. s2 = {1, 2, 3, 5}
  set<int> s3 = s2;                 // Copy constructor
  set<int, greater<int>> s_desc;    // Set sorted in descending order

  // === Modifiers ===

  // Insert element. Returns pair<iterator, bool>
  // The bool is true if insert happened, false if key already existed.
  // Complexity: O(log N)
  s1.insert(10);
  s1.insert(5);
  s1.insert(10); // Fails, 10 is already there. s1 = {5, 10}

  // Erase by key. Returns number of elements erased (0 or 1).
  // Complexity: O(log N)
  size_t count = s1.erase(10); // s1 = {5}

  // Erase by iterator.
  // Complexity: O(1) amortized
  auto it_erase = s2.find(3);
  if (it_erase != s2.end())
  {
    s2.erase(it_erase); // s2 = {1, 2, 5}
  }

  // === Capacity ===
  s1.size();  // Returns size.   return type: size_t. Complexity: O(1)
  s1.empty(); // empty or not?   return type: bool. Complexity: O(1)
  s1.clear(); // Empties the set. return type: void. Complexity: O(N)

  // === Lookup / Searching ===

  // Finds element by key. Returns iterator.
  // Returns s.end() if not found.
  // Complexity: O(log N)
  auto it_find = s2.find(2); // it_find points to 2
  if (it_find == s2.end())
  {
    // not found
  }

  // Counts elements with key. Returns 0 or 1 for set.
  // Complexity: O(log N)
  size_t num = s2.count(5); // num is 1

  // --- (These work because set is ordered) ---

  // Finds iterator to first element with key *not less than* 2.
  // Complexity: O(log N)
  auto it_lower = s2.lower_bound(2); // points to 2

  // Finds iterator to first element with key *greater than* 2.
  // Complexity: O(log N)
  auto it_upper = s2.upper_bound(2); // points to 5

  // === Iterators ===
  s2.begin();  // Iterator to first element (smallest). 1
  s2.end();    // Iterator to *after* last element.
  s2.rbegin(); // Reverse iterator to last element (largest). 5
  s2.rend();   // Reverse iterator to *before* first element.

  // Example: Iterate and print (in sorted order)
  for (int x : s2)
  {
    // cout << x << " "; // Output: 1 2 5
  }

  return 0;
}