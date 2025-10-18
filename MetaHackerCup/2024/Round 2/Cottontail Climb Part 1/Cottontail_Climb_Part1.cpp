#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define mod 1000000007

long long power(long long a, long long b)
{
  if (b == 0)
    return 1;

  long long remainderMultiply = 1;
  while (b > 1)
  {
    if (b % 2 == 0)
    {
      a *= a;
      b /= 2;
    }
    else
    {
      remainderMultiply *= a;
      a *= a;
      b = (b - 1) / 2;
    }
  }
  return remainderMultiply * a;
}

ll createNum(int digCnt, int firstDig)
{
  if (digCnt % 2 == 0)
  {
    return -1;
  }
  else if (firstDig > 9 - digCnt / 2)
  {
    return -1;
  }

  ll retNum = 0;
  ll multiplier = 1;
  for (int i = digCnt; i > 0; i -= 2)
  {
    ll currNum = (power(10, i - 1) + (i > 1 ? 1 : 0)) * firstDig;
    retNum += currNum * multiplier;
    firstDig++;
    multiplier *= 10;
  }
  return retNum;
}

ll incNum(ll num, int digCnt)
{
  if (num % 10 + 1 > 9 - digCnt / 2 || digCnt % 2 == 0)
  {
    return -1;
  }
  ll multiplier = 1;
  while (multiplier <= num)
  {
    num += multiplier;
    multiplier *= 10;
  }
  return num;
}

int main()
{

  ifstream infile("cottontail_climb_part_1_input.txt");
  ofstream outfile("cottontail_climb_part_1_output.txt");
  fast_io;
  int T;
  infile >> T;
  // cout << incNum(createNum(17, 1), 17) << endl;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";
    ll a, b, m;
    infile >> a >> b >> m;

    ll aCpy = a;
    ll minDigCnt = 0;
    while (aCpy > 0)
    {
      minDigCnt++;
      aCpy /= 10;
    }
    minDigCnt += minDigCnt % 2 == 1 ? 0 : 1;
    ll runVal = createNum(minDigCnt, 1);
    // cout << "HI" << endl;

    while (runVal < a)
    {
      runVal = incNum(runVal, minDigCnt);
      if (runVal == -1)
      {
        minDigCnt += 2;
        createNum(minDigCnt, 1);
      }
    }
    // cout << runVal << endl;

    int finalCnt = 0;
    while (runVal <= b)
    {
      // cout << runVal << endl;
      // cout << "HELLO" << endl;
      if (runVal % m == 0 && runVal != -1)
      {
        finalCnt++;
      }

      runVal = incNum(runVal, minDigCnt);
      if (runVal == -1)
      {
        minDigCnt += 2;
        runVal = createNum(minDigCnt, 1);
      }
    }
    // cout << runVal << endl;
    outfile << finalCnt << endl;
  }

  return 0;
}