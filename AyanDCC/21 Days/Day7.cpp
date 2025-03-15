#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, x, y;
  cin >> n >> x >> y;

  x--;
  y--;

  int sq_n{n * n};
  vector<vector<int>> matrix(sq_n, std::vector<int>(sq_n));

  for (int i = 0; i < sq_n; i++)
    for (int j = 0; j < sq_n; j++)
      cin >> matrix.at(i).at(j);

  int super_x{x - x % n}, super_y{y - y % n};
  long long reqd_sum{0};

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      reqd_sum += matrix.at(i + super_x).at(j + super_y);

  // cout << super_x << endl;
  // cout << super_y << endl;
  cout << reqd_sum << endl;
}