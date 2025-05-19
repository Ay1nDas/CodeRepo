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
  int n;
  cin >> n;

  unordered_map<int, int> mapped_value;
  int max_num = 0;

  while (n--)
  {
    int num;
    cin >> num;

    mapped_value[num] += num;
    max_num = max(num, max_num);
  }

  int odd = 0, even = 0;
  vector<int> even_arr, odd_arr;

  for (int i = 1; i <= max_num; i++){
    
  }

  return 0;
}