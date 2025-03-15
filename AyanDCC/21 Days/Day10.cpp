#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int test_cases{0};
  cin >> test_cases;
  while (test_cases--)
  {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> ind(m);
    vector<int> b(m);

    for (int i = 0; i < n; i++)
      cin >> a.at(i);
    for (int i = 0; i < m; i++)
      cin >> ind.at(i);
    for (int i = 0; i < m; i++)
      cin >> b.at(i);

    sort(ind.begin(), ind.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < m; i++)
      a.at(ind.at(i) - 1) = b.at(i);

    for (int i : a)
    {
      cout << i << " ";
    }
    cout << endl;
  }
}