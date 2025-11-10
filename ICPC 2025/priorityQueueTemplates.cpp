#include <iostream>
#include <queue> // Contains priority_queue
#include <vector>
#include <string>
using namespace std;

// std::priority_queue is a heap (usually a max-heap).
// Allows fast insertion and retrieval of the *largest* element.
//
// .top() -> Get largest element.  Complexity: O(1)
// .push() -> Insert element.     Complexity: O(log N)
// .pop()  -> Remove largest element. Complexity: O(log N)
//
// Note: You cannot iterate over a priority_queue.

int main()
{
  // === Constructors ===

  // 1. Max Heap (Default)
  // Stores largest element at the top.
  priority_queue<int> pq_max;

  // 2. Min Heap
  // Stores smallest element at the top.
  // Requires a container (vector<int>) and a comparator (greater<int>)
  priority_queue<int, vector<int>, greater<int>> pq_min;

  // 3. Custom Comparator (e.g., for pairs)
  // Example: Max heap of pairs, ordered by the first element.
  priority_queue<pair<int, int>> pq_pair_max;

  // Example: Min heap of pairs, ordered by the first element.
  using pi = pair<int, int>;
  priority_queue<pi, vector<pi>, greater<pi>> pq_pair_min;

  // === Max Heap Example ===
  pq_max.push(10);
  pq_max.push(5);
  pq_max.push(20); // pq_max = {20, 10, 5}

  // Get top (largest) element.
  // Complexity: O(1)
  cout << "Max heap top: " << pq_max.top() << endl; // 20

  // Remove top (largest) element.
  // Complexity: O(log N)
  pq_max.pop();                                               // pq_max = {10, 5}
  cout << "Max heap top after pop: " << pq_max.top() << endl; // 10

  // === Min Heap Example ===
  pq_min.push(10);
  pq_min.push(5);
  pq_min.push(20); // pq_min = {5, 10, 20}

  // Get top (smallest) element.
  // Complexity: O(1)
  cout << "Min heap top: " << pq_min.top() << endl; // 5

  // Remove top (smallest) element.
  // Complexity: O(log N)
  pq_min.pop();                                               // pq_min = {10, 20}
  cout << "Min heap top after pop: " << pq_min.top() << endl; // 10

  // === Capacity ===
  pq_max.size();  // Returns size.   return type: size_t. Complexity: O(1)
  pq_max.empty(); // empty or not?   return type: bool. Complexity: O(1)

  // Note: .clear() does not exist. To clear, swap with empty one:
  priority_queue<int> empty_pq;
  pq_max.swap(empty_pq); // pq_max is now empty

  return 0;
}