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

int findSub(vector<int> &sub, vector<vector<int>> &vals, int boss)
{
  int emp = 0;
  for (auto i : vals.at(boss))
  {
    sub.at(i) = findSub(sub, vals, i);
    emp += 1 + sub.at(i);
  }
  return emp;
}

int main()
{

  fast_io;

  int n;
  cin >> n;
  vector<int> sub(n + 1);
  vector<vector<int>> vals(n + 1);

  for (int i = 2; i <= n; i++)
  {
    int tmp;
    cin >> tmp;

    vals.at(tmp).push_back(i);
  }

  sub.at(1) = findSub(sub, vals, 1);
  for (int i = 1; i < sub.size(); i++)
  {
    cout << sub.at(i) << " ";
  }
  cout << endl;

  return 0;
}