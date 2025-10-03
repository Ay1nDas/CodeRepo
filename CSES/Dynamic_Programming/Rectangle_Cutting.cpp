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
  int a, b;
  cin >> a >> b;

  vector<vector<int>> rectangles(a + 1, vector<int>(b + 1));
  for (int i = 1; i <= b; i++)
    rectangles.at(1).at(i) = i - 1;
  for (int i = 1; i <= a; i++)
    rectangles.at(i).at(1) = i - 1;

  for (int i = 2; i <= a; i++)
  {
    for (int j = 2; j <= b; j++)
    {
      if (i == j)
      {
        rectangles.at(i).at(j) = 0;
      }
      else
      {
        int minCut = INT_MAX;
        for (int c = i - 1; c > 0; c--)
        {
          int currCut = rectangles.at(c).at(j) + rectangles.at(i - c).at(j) + 1;
          minCut = min(currCut, minCut);
        }

        for (int r = j - 1; r > 0; r--)
        {
          int currCut = rectangles.at(i).at(r) + rectangles.at(i).at(j - r) + 1;
          minCut = min(currCut, minCut);
        }

        rectangles.at(i).at(j) = minCut;
      }
    }
  }

  cout << rectangles.at(a).at(b) << endl;

  return 0;
}