#include <iostream>
#include <set> // multiset is in the <set> header
#include <string>
using namespace std;

// std::multiset is an ordered set (Red-Black Tree).
// It's just like std::set, but it *allows duplicate keys*.
// Keys are stored in sorted order.
// All operations (insert, erase, find) are O(log N).

int main()
{
  // === Constructors ===
  multiset<int> ms1;                      // Empty multiset
  multiset<int> ms2 = {1, 5, 3, 2, 5, 1}; // From initializer list. ms2 = {1, 1, 2, 3, 5, 5}
  multiset<int> ms3 = ms2;                // Copy constructor
  multiset<int, greater<int>> ms_desc;    // Sorted in descending order

  // === Modifiers ===

  // Insert element. Returns an iterator to the newly inserted element.
  // Unlike std::set, it *always* inserts.
  // Complexity: O(log N)
  ms1.insert(10);
  ms1.insert(5);
  ms1.insert(10); // Inserts *another* 10. ms1 = {5, 10, 10}

  // --- Erase (IMPORTANT: different from std::set) ---

  // 1. Erase by key:
  // **Removes ALL elements matching the key.**
  // Returns the number of elements erased.
  // Complexity: O(log N + K) where K is the number of erased elements.
  size_t count = ms1.erase(10); // Erases *both* 10s. ms1 = {5}. count = 2

  // 2. Erase by iterator:
  // **Removes only the single element at that iterator's position.**
  // Complexity: O(1) amortized
  auto it_erase = ms2.find(5); // Finds the *first* 5
  if (it_erase != ms2.end())
  {
    ms2.erase(it_erase); // Erases only the first 5. ms2 = {1, 1, 2, 3, 5}
  }

  // === Capacity ===
  ms2.size();  // Returns size (5). return type: size_t. Complexity: O(1)
  ms2.empty(); // empty or not?   return type: bool. Complexity: O(1)
  ms2.clear(); // Empties the set. return type: void. Complexity: O(N)

  // === Lookup / Searching ===
  ms2 = {1, 1, 2, 3, 5, 5}; // Reset

  // Finds iterator to the *first* element matching the key.
  // Returns ms.end() if not found.
  // Complexity: O(log N)
  auto it_find = ms2.find(5); // it_find points to the first 5
  if (it_find == ms2.end())
  {
    // not found
  }

  // Counts elements with a specific key.
  // Complexity: O(log N + K) where K is the number of matching elements.
  size_t num = ms2.count(1); // num is 2

  // --- (These work because multiset is ordered) ---

  // Finds iterator to first element with key *not less than* 3.
  // Complexity: O(log N)
  auto it_lower = ms2.lower_bound(3); // points to 3

  // Finds iterator to first element with key *greater than* 3.
  // Complexity: O(log N)
  auto it_upper = ms2.upper_bound(3); // points to the first 5

  // .equal_range(key) returns a pair of iterators [lower_bound, upper_bound)
  // This gives you the range of *all* elements matching the key.
  // Complexity: O(log N)
  auto range = ms2.equal_range(5);
  // range.first is lower_bound(5) (points to first 5)
  // range.second is upper_bound(5) (points to element after last 5)

  // Iterate just over the 5s
  for (auto it = range.first; it != range.second; ++it)
  {
    // cout << *it << " "; // 5 5
  }

  // === Iterators ===
  ms2.begin();  // Iterator to first element (smallest). 1
  ms2.end();    // Iterator to *after* last element.
  ms2.rbegin(); // Reverse iterator to last element (largest). 5
  ms2.rend();   // Reverse iterator to *before* first element.

  // Example: Iterate and print (in sorted order)
  for (int x : ms2)
  {
    // cout << x << " "; // Output: 1 1 2 3 5 5
  }

  return 0;
}