#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// std::unordered_map is a Hash Table.
// Average time for insert, erase, and find is O(1).
// Worst-case time (due to hash collisions) is O(N).
// Keys are NOT stored in sorted order.

int main()
{
  // === Constructors ===
  unordered_map<string, int> um1;                            // Empty
  unordered_map<int, int> um2 = {{1, 10}, {3, 30}, {2, 20}}; // Initializer list
  unordered_map<string, int> um3 = um1;                      // Copy constructor

  // === Element Access / Modifiers ===

  // Access/Insert using operator[].
  // If "one" doesn't exist, it's created and value-initialized (to 0 for int).
  // Complexity: O(1) average, O(N) worst
  um1["one"] = 1;       // Inserts {"one", 1}
  um1["one"] = 11;      // Modifies {"one", 11}
  int val = um1["one"]; // Accesses value (11)

  // Access using .at(). Throws std::out_of_range if key doesn't exist.
  // Complexity: O(1) average, O(N) worst
  val = um1.at("one");

  // Insert using .insert().
  // Complexity: O(1) average, O(N) worst
  um1.insert({"four", 4});
  um1.insert(make_pair("five", 5));

  // Erase by key. Returns number of elements erased (0 or 1).
  // Complexity: O(1) average, O(N) worst
  size_t count = um1.erase("one");

  // Erase by iterator.
  // Complexity: O(1) average
  auto it_erase = um1.find("four");
  if (it_erase != um1.end())
  {
    um1.erase(it_erase);
  }

  // === Capacity ===
  um1.size();  // Returns size.   return type: size_t. Complexity: O(1)
  um1.empty(); // empty or not?   return type: bool. Complexity: O(1)
  um1.clear(); // Empties the map. return type: void. Complexity: O(N)

  // === Lookup / Searching ===

  // Finds element by key. Returns iterator.
  // Returns um.end() if not found.
  // Complexity: O(1) average, O(N) worst
  auto it_find = um2.find(2); // it_find points to {2, 20}
  if (it_find == um2.end())
  {
    // not found
  }

  // Counts elements with key. Returns 0 or 1 for unordered_map.
  // Complexity: O(1) average, O(N) worst
  size_t num = um2.count(3); // num is 1

  // === Iterators ===
  um2.begin(); // Iterator to first element (order is arbitrary).
  um2.end();   // Iterator to *after* last element.

  // Example: Iterate and print (order is not guaranteed!)
  for (auto const &[key, val] : um2)
  {
    // cout << "Key: " << key << " Value: " << val << endl;
  }

  return 0;
}