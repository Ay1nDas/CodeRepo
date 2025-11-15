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
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    vector<long long> P(n + 1, 0);

    long long original_sum = 0;
    for (int i = 1; i <= n; ++i)
    {
      cin >> a[i];
      P[i] = P[i - 1] + a[i];
      original_sum += a[i];
    }

    vector<long long> B(n + 1);
    vector<long long> M(n + 1);

    long long max_B_so_far = numeric_limits<long long>::min();

    for (int l = 1; l <= n; ++l)
    {
      long long ll = l;
      B[l] = ll - ll * ll + P[l - 1];

      if (l == 1 || B[l] > max_B_so_far)
      {
        max_B_so_far = B[l];
      }
      M[l] = max_B_so_far;
    }

    long long max_delta = 0;

    for (int r = 1; r <= n; ++r)
    {
      long long rr = r;
      long long D_r = rr * rr + rr - P[r];

      long long current_delta = D_r + M[r];

      max_delta = max(max_delta, current_delta);
    }

    cout << original_sum + max_delta << endl;
  }

  return 0;
}