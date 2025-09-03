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

int getMaxChunk(vector<int> &addedVal, int start, int end)
{
  int even = 0, odd = 0;
  for (int i = start; i < end; i += 2)
  {
    even += addedVal.at(i);
    if (i + 1 < end)
      odd += addedVal.at(i + 1);
  }

  int opt_val = 0;
  int idx = start;

  while (idx < end)
  {
    if (even > odd)
    {
      if ((idx - start) % 2 == 0)
      {
        opt_val += addedVal.at(idx);
        even -= addedVal.at(idx);
        odd -= (idx + 1 < end) ? addedVal.at(idx + 1) : 0;
        idx += 2;
      }
      else
      {
        opt_val += addedVal.at(idx + 1);
        odd -= addedVal.at(idx);
        even -= (idx + 1 < end) ? addedVal.at(idx + 1) : 0;
        odd -= (idx + 2 < end) ? addedVal.at(idx + 2) : 0;
        idx += 3;
      }
    }
    else if (odd > even)
    {
      if ((idx - start) % 2 == 0)
      {
        opt_val += addedVal.at(idx + 1);
        even -= addedVal.at(idx);
        odd -= (idx + 1 < end) ? addedVal.at(idx + 1) : 0;
        even -= (idx + 2 < end) ? addedVal.at(idx + 2) : 0;
        idx += 3;
      }
      else
      {
        opt_val += addedVal.at(idx);
        odd -= addedVal.at(idx);
        even -= (idx + 1 < end) ? addedVal.at(idx + 1) : 0;
        idx += 1;
      }
    }
    else if (idx + 1 < end && addedVal.at(idx) >= addedVal.at(idx + 1))
    {
      opt_val += addedVal.at(idx);
      if ((idx - start) % 2 == 0)
      {
        even -= addedVal.at(idx);
        odd -= addedVal.at(idx + 1);
      }
      else
      {
        odd -= addedVal.at(idx);
        even -= addedVal.at(idx + 1);
      }
      idx += 2;
    }
    else
    {
      opt_val += addedVal.at(idx + 1);
      if ((idx + 1 - start) % 2 == 0)
      {
        odd -= addedVal.at(idx);
        even -= addedVal.at(idx + 1);
        odd -= (idx + 2 < end) ? addedVal.at(idx + 2) : 0;
      }
      else
      {
        even -= addedVal.at(idx);
        odd -= addedVal.at(idx + 1);
        even -= (idx + 2 < end) ? addedVal.at(idx + 2) : 0;
      }
      idx += 3;
    }
  }

  return opt_val;
}

int main()
{

  fast_io;
  int n;
  cin >> n;

  vector<int> values(n);
  for (int i = 0; i < n; i++)
    cin >> values.at(i);

  sort(values.rbegin(), values.rend());
  vector<int> addedVal;

  addedVal.push_back(0);
  int ul = values.at(0);

  for (int i = 0; i < n; i++)
  {
    while (values.at(i) != ul)
    {
      addedVal.push_back(0);
      ul--;
    }
    addedVal.back() += values.at(i);
  }

  for (auto i : addedVal)
  {
    cout << i << " ";
  }
  cout << endl;

  int final_val = 0;
  int streak_st = 0, streak_end = -1;

  for (int i = 0; i < addedVal.size(); i++)
  {
    if (addedVal.at(i) == 0)
    {
      if (streak_st <= streak_end && streak_st >= 0 && streak_end < addedVal.size())
        final_val += getMaxChunk(addedVal, streak_st, streak_end + 1);

      streak_end = i;
      streak_st = i + 1;
    }
    else
    {
      streak_end++;
    }
  }
  if (streak_st <= streak_end && streak_st >= 0 && streak_end < addedVal.size())
    final_val += getMaxChunk(addedVal, streak_st, streak_end + 1);

  cout << final_val << endl;
  return 0;
}