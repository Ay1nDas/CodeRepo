#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
  int n;
  cin >> n;

  unordered_map<int, int> caskets;
  int total_caskets{0};

  for (int i = 1; i <= n; i++)
  {
    int current_caskets{0};
    cin >> current_caskets;

    for (int j = 1; j <= current_caskets; j++)
    {
      caskets[total_caskets + j] = i;
    }
    total_caskets += current_caskets;
  }

  int m{0};
  cin >> m;
  while (m--)
  {
    int reqd_casket{0};
    cin >> reqd_casket;

    cout << caskets[reqd_casket] << endl;
  }
}
