#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> caskets(n);
  cin >> caskets.at(0);

  for (int i = 1; i < n; i++)
  {
    cin >> caskets.at(i);
    caskets.at(i) += caskets.at(i - 1);
  }

  int m{0};
  cin >> m;
  while (m--)
  {
    int reqd_casket;
    cin >> reqd_casket;

    int index{0};
    while (caskets.at(index) < reqd_casket)
    {
      index++;
    }

    cout << index + 1 << endl;
  }
}
