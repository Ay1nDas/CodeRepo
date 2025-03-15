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
  vector<int> angles(n);
  angles.push_back(0);
  angles.push_back(360);
  int degree = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> angles.at(i);
    degree += angles.at(i);
    if (degree >= 360)
      degree -= 360;

    angles.at(i) = degree;
  }

  sort(angles.begin(), angles.end());
  int max_angle = 0;

  for (int i = 0; i < n + 1; i++)
  {
    if (angles.at(i + 1) - angles.at(i) > max_angle)
    {
      max_angle = angles.at(i + 1) - angles.at(i);
    }
  }

  cout << max_angle << endl;

  return 0;
}