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

void recursion(vector<int> &arr, int &max_sum)
{
  int sum = 0;

  if (arr.size() <= 1)
  {
    if (arr.at(0) > max_sum)
      max_sum = arr.at(0);
    return;
  }

  vector<int> arr_left(arr.size() - 1);
  vector<int> arr_right(arr.size() - 1);

  for (int i = 0; i + 1 < arr.size(); i++)
  {
    arr_left.at(i) = arr.at(i + 1) - arr.at(i);
    arr_right.at(arr.size() - 2 - i) = arr_left.at(i);
  }
  int left_sum = arr.at(arr.size() - 1) - arr.at(0);
  int right_sum = -left_sum;

  if (abs(left_sum) >= max_sum)
    max_sum = abs(left_sum);

  recursion(arr_left, max_sum);
  recursion(arr_right, max_sum);
}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<int> seq(n);
    vector<int> rseq(n);
    int max_sum = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> seq.at(i);
      rseq.at(n - 1 - i) = seq.at(i);
      max_sum += seq.at(i);
    }

    int left_sum = seq.at(n - 1) - seq.at(0);
    if (abs(left_sum) > max_sum)
    {
      max_sum = abs(left_sum);
    }

    recursion(seq, max_sum);
    recursion(rseq, max_sum);

    cout << max_sum << endl;
  }

  return 0;
}