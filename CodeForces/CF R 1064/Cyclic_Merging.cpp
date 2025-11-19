#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

class linkedList
{
public:
  struct Node
  {
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
  };

private:
  Node *head;
  int size;

public:
  linkedList(const std::vector<int> &vec) : head(nullptr), size(0)
  {
    if (vec.empty())
    {
      return;
    }

    head = new Node(vec[0]);
    size = 1;

    if (vec.size() == 1)
    {
      head->next = head;
      head->prev = head;
      return;
    }

    Node *currentNode = head;
    for (size_t i = 1; i < vec.size(); ++i)
    {
      Node *newNode = new Node(vec[i]);

      currentNode->next = newNode;
      newNode->prev = currentNode;

      currentNode = newNode;
      size++;
    }

    currentNode->next = head;
    head->prev = currentNode;
  }

  ~linkedList()
  {
    if (!head)
    {
      return;
    }

    Node *current = head;
    Node *nextNode = nullptr;

    do
    {
      nextNode = current->next;
      delete current;
      current = nextNode;
    } while (current != head);

    head = nullptr;
    size = 0;
  }

  void removeNode(Node *nodeToRemove)
  {
    if (!nodeToRemove || !head)
    {
      return;
    }

    if (size == 1 && nodeToRemove == head)
    {
      delete head;
      head = nullptr;
      size = 0;
      return;
    }

    Node *prevNode = nodeToRemove->prev;
    Node *nextNode = nodeToRemove->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    if (nodeToRemove == head)
    {
      head = nextNode;
    }

    delete nodeToRemove;
    size--;
  }

  std::pair<int, int> findMaxPairs(Node *node)
  {
    if (!node)
    {
      return {};
    }

    int maxWithPrev = std::max(node->data, node->prev->data);
    int maxWithNext = std::max(node->data, node->next->data);

    return {maxWithPrev, maxWithNext};
  }

  Node *getHead()
  {
    return head;
  }

  int getSize()
  {
    return size;
  }

  void printList()
  {
    if (!head)
    {
      std::cout << "List is empty." << std::endl;
      return;
    }

    Node *current = head;
    std::cout << "List (forward): ";
    do
    {
      std::cout << current->data << " <-> ";
      current = current->next;
    } while (current != head);
    std::cout << "(back to " << head->data << ")" << std::endl;
  }
};

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr)
    {
      cin >> i;
    }

    linkedList lk(arr);
    // lk.printList();

    auto currNode = lk.getHead();

    unordered_map<int, set<linkedList::Node *>> costPosn;
    multiset<int> costs;

    for (int i = 0; i < n; i++)
    {
      int currCost = max(currNode->data, currNode->next->data);
      costPosn[currCost].insert(currNode);
      currNode = currNode->next;
      costs.insert(currCost);
    }

    // for (auto i : costs)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    ll totalCost = 0;

    for (int merge_count = 0; merge_count < n - 1; ++merge_count)
    {
      linkedList::Node *node1, *node2, *rmvNode, *prevNode, *nextNode;
      int minVal;

      while (true)
      {
        if (costs.empty())
        {
          break;
        }
        minVal = *costs.begin();
        costs.erase(costs.begin());

        if (costPosn[minVal].empty())
        {
          continue;
        }

        node1 = *costPosn[minVal].begin();
        costPosn[minVal].erase(costPosn[minVal].begin());

        break;
      }

      totalCost += minVal;

      node2 = node1->next;
      rmvNode = node2;
      prevNode = node1;
      nextNode = node2->next;

      int cost_prev = max(prevNode->prev->data, prevNode->data);
      int cost_next = max(rmvNode->data, nextNode->data);

      auto it1 = costs.find(cost_prev);
      if (it1 != costs.end())
      {
        costs.erase(it1);
        costPosn[cost_prev].erase(prevNode->prev);
      }

      auto it2 = costs.find(cost_next);
      if (it2 != costs.end())
      {
        costs.erase(it2);
        costPosn[cost_next].erase(rmvNode);
      }

      node1->data = max(node1->data, rmvNode->data);

      int new_cost_prev = max(prevNode->prev->data, node1->data);
      costs.insert(new_cost_prev);
      costPosn[new_cost_prev].insert(prevNode->prev);

      int new_cost_next = max(node1->data, nextNode->data);
      costs.insert(new_cost_next);
      costPosn[new_cost_next].insert(node1);

      lk.removeNode(rmvNode);
    }

    cout << totalCost << endl;
  }

  return 0;
}