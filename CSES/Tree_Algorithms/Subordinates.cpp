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

int findSub(vector<int> &sub, vector<int> &vals, int boss)
{
  int emp = 0;
  for (int i = 0; i < vals.size(); i++)
  {
    if (vals.at(i) == boss)
    {
      if (sub.at(i) == 0)
        sub.at(i) = findSub(sub, vals, i);
      emp += 1 + sub.at(i);
    }
  }
  return emp;
}

int main()
{

  fast_io;

  int n;
  cin >> n;
  vector<int> sub(n + 1);
  vector<int> vals(n + 1);

  for (int i = 2; i <= n; i++)
    cin >> vals.at(i);

  for (int i = 1; i <= n; i++)
  {
    if (sub.at(i) == 0)
      sub.at(i) = findSub(sub, vals, i);
  }

  for (int i = 1; i < sub.size(); i++)
  {
    cout << sub.at(i) << " ";
  }
  cout << endl;

  return 0;
}