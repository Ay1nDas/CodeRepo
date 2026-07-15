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

int main()
{

  fast_io;

  int n, k;
  cin >> n >> k;

  unordered_map<int, int> watered;

  for (int i = 0; i < k; i++)
  {
    int start, end;
    cin >> start >> end;

    for (start; start <= end; start++)
      watered[start]++;
  }

  for (int i = 1; i <= n; i++)
    cout << watered[i] << " ";
  cout << endl;

  return 0;
}