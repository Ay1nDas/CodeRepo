#include <iostream>
#include <map>
#include <string>
using namespace std;

// std::map is an ordered map (Red-Black Tree).
// All operations (insert, erase, find) are O(log N).
// Keys are stored in sorted order.
//
// For O(1) average time, use std::unordered_map (Hash Table).
// API is nearly identical, but unordered_map is not sorted.

int main()
{
  // === Constructors ===
  map<string, int> m1;                            // Empty map
  map<int, int> m2 = {{1, 10}, {3, 30}, {2, 20}}; // From initializer list
  map<string, int> m3 = m1;                       // Copy constructor

  // === Element Access / Modifiers ===

  // Access/Insert using operator[].
  // If "one" doesn't exist, it's created and value-initialized (to 0 for int).
  // Complexity: O(log N)
  m1["one"] = 1;       // Inserts {"one", 1}
  m1["one"] = 11;      // Modifies {"one", 11}
  int val = m1["one"]; // Accesses value (11)

  // Access using .at(). Throws std::out_of_range if key doesn't exist.
  // Complexity: O(log N)
  val = m1.at("one");

  // Insert using .insert(). Returns pair<iterator, bool>
  // The bool is true if insert happened, false if key already existed.
  // Complexity: O(log N)
  m1.insert({"four", 4});
  m1.insert(make_pair("five", 5)); // C++11 way

  // Erase by key. Returns number of elements erased (0 or 1).
  // Complexity: O(log N)
  size_t count = m1.erase("one");

  // Erase by iterator.
  // Complexity: O(1) amortized
  auto it_erase = m1.find("four");
  if (it_erase != m1.end())
  {
    m1.erase(it_erase);
  }

  // === Capacity ===
  m1.size();  // Returns size.   return type: size_t. Complexity: O(1)
  m1.empty(); // empty or not?   return type: bool. Complexity: O(1)
  m1.clear(); // Empties the map. return type: void. Complexity: O(N)

  // === Lookup / Searching ===

  // Finds element by key. Returns iterator.
  // Returns m.end() if not found.
  // Complexity: O(log N)
  auto it_find = m2.find(2); // it_find points to {2, 20}
  if (it_find == m2.end())
  {
    // not found
  }

  // Counts elements with key. Returns 0 or 1 for map.
  // Complexity: O(log N)
  size_t num = m2.count(3); // num is 1

  // --- (These work because map is ordered) ---

  // Finds iterator to first element with key *not less than* 2.
  // Complexity: O(log N)
  auto it_lower = m2.lower_bound(2); // points to {2, 20}

  // Finds iterator to first element with key *greater than* 2.
  // Complexity: O(log N)
  auto it_upper = m2.upper_bound(2); // points to {3, 30}

  // === Iterators ===
  m2.begin();  // Iterator to first element (sorted by key). {1, 10}
  m2.end();    // Iterator to *after* last element.
  m2.rbegin(); // Reverse iterator to last element. {3, 30}
  m2.rend();   // Reverse iterator to *before* first element.

  // Example: Iterate and print (C++17 structured bindings)
  // Iteration is in key-sorted order!
  for (auto const &[key, val] : m2)
  {
    // cout << "Key: " << key << " Value: " << val << endl;
    // Output:
    // Key: 1 Value: 10
    // Key: 2 Value: 20
    // Key: 3 Value: 30
  }

  // Example: Iterate and print (C++11)
  for (auto const &p : m2)
  {
    // cout << "Key: " << p.first << " Value: " << p.second << endl;
  }

  return 0;
}