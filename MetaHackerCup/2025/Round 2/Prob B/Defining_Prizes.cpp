#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
#define mod 1000000007

vector<ll> prefixSum;
vector<ll> sorted;

ll sum_min(int peplCnt)
{
  if (peplCnt == 0)
    return 0;

  auto it = lower_bound(allrev(sorted), (ll)peplCnt);

  int j = distance(sorted.rbegin(), it);

  ll sum = 0;
  sum += static_cast<ll>(j) * peplCnt;

  if (j < sorted.size())
  {
    sum += (prefixSum.back() - (j == 0 ? 0 : prefixSum[j - 1]));
  }

  return sum;
}

bool check(int k, int M, const vector<ll> &revGrp)
{
  if (k == 0)
    return true;
  if (k > M && !revGrp.empty() && revGrp[0] > 0)
    return false;

  vector<ll> przNeed;
  ll total = 0;
  for (int i = 0; i < k; i++)
  {
    int przCnt = k - i;
    for (int j = 0; j < revGrp[i]; ++j)
    {
      przNeed.push_back(przCnt);
    }
    total += revGrp[i] * przCnt;
  }

  if (total > prefixSum.back())
  {
    return false;
  }

  int reward = przNeed.size();
  ll currNeed = 0;

  for (int i = 1; i <= reward; ++i)
  {
    currNeed += przNeed[i - 1];

    if (currNeed > sum_min(i))
    {
      return false;
    }
  }
  return true;
}

int main()
{

  ifstream infile("defining_prizes_input.txt");
  ofstream outfile("defining_prizes_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";

    int n, m;
    infile >> n >> m;

    map<int, int> scCnt;
    for (int i = 0; i < n; i++)
    {
      int sc;
      infile >> sc;
      scCnt[sc]++;
    }

    vector<ll> grpSizes;
    for (auto &[sc, cnt] : scCnt)
    {
      grpSizes.push_back(cnt);
    }

    sorted.resize(m);
    prefixSum.assign(m + 1, 0);

    for (int i = 0; i < m; i++)
    {
      infile >> sorted[i];
    }
    sort(allrev(sorted));

    prefixSum[0] = 0;
    for (int i = 0; i < m; i++)
    {
      prefixSum[i + 1] = prefixSum[i] + sorted[i];
    }
    prefixSum.assign(m, 0);
    if (m > 0)
    {
      prefixSum[0] = sorted[0];
      for (int i = 1; i < m; i++)
      {
        prefixSum[i] = prefixSum[i - 1] + sorted[i];
      }
    }

    if (grpSizes.size() == 0)
    {
      outfile << 0 << endl;
      continue;
    }

    vector<ll> revGrp;
    for (int i = grpSizes.size() - 1; i >= 0; i--)
    {
      revGrp.push_back(grpSizes[i]);
    }

    vector<ll> rPrefixSum(grpSizes.size());
    rPrefixSum[0] = revGrp[0];
    for (int i = 1; i < grpSizes.size(); i++)
    {
      rPrefixSum[i] = rPrefixSum[i - 1] + revGrp[i];
    }

    int ans = 0;
    int lft = 0;
    int rht = grpSizes.size();

    while (lft <= rht)
    {
      int mid = lft + (rht - lft) / 2;
      if (check(mid, m, revGrp))
      {
        ans = mid;
        lft = mid + 1;
      }
      else
      {
        rht = mid - 1;
      }
    }

    if (ans == 0)
    {
      outfile << 0 << endl;
    }
    else
    {
      outfile << rPrefixSum[ans - 1] << endl;
    }
  }

  return 0;
}