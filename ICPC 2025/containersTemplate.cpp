#include <iostream>
#include <stack> // For stack
#include <queue> // For queue and priority_queue
#include <deque> // For deque
#include <string>
using namespace std;

int main()
{
  // === std::stack ===
  // LIFO (Last-In, First-Out).
  // Operations are O(1).
  cout << "--- Stack ---" << endl;
  stack<int> s;
  s.push(10);                               // s = {10}
  s.push(20);                               // s = {10, 20}
  cout << "Stack top: " << s.top() << endl; // 20

  s.pop();                                            // Removes 20. s = {10}
  cout << "Stack top after pop: " << s.top() << endl; // 10

  cout << "Stack size: " << s.size() << endl;   // 1
  cout << "Stack empty? " << s.empty() << endl; // false

  // ---
  // === std::queue ===
  // FIFO (First-In, First-Out).
  // Operations are O(1).
  cout << "\n--- Queue ---" << endl;
  queue<int> q;
  q.push(10);                                             // q = {10}
  q.push(20);                                             // q = {10, 20}
  cout << "Queue front: " << q.front() << endl;           // 10
  cout << "Queue back: " << q.back() << endl;             // 20
  q.pop();                                                // Removes 10. q = {20}
  cout << "Queue front after pop: " << q.front() << endl; // 20
  cout << "Queue size: " << q.size() << endl;             // 1
  cout << "Queue empty? " << q.empty() << endl;           // false

  // ---
  // === std::deque ===
  // Double-Ended Queue.
  // All push/pop from front/back are O(1).
  // Random access (at, []) is O(1).
  cout << "\n--- Deque ---" << endl;
  deque<int> d;

  d.push_back(10); // d = {10}
  d.push_back(20); // d = {10, 20}
  d.push_front(5); // d = {5, 10, 20}

  cout << "Deque front: " << d.front() << endl; // 5
  cout << "Deque back: " << d.back() << endl;   // 20
  cout << "Deque at[1]: " << d[1] << endl;      // 10

  d.pop_back();                                            // Removes 20. d = {5, 10}
  d.pop_front();                                           // Removes 5. d = {10}
  cout << "Deque front after pops: " << d.front() << endl; // 10
  cout << "Deque size: " << d.size() << endl;              // 1
  cout << "Deque empty? " << d.empty() << endl;            // false
  d.clear();                                               // Empties the deque.

  return 0;
}