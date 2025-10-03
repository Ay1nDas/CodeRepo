#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Jewel
{
  int quality;
  int weight;
};

int n, k;
std::vector<Jewel> jewels;

bool check(double x)
{
  std::vector<double> v(n);
  for (int i = 0; i < n; ++i)
  {
    v[i] = (double)jewels[i].quality - x * jewels[i].weight;
  }

  std::sort(v.rbegin(), v.rend());

  double sum_of_top_k = 0;
  for (int i = 0; i < k; ++i)
    sum_of_top_k += v[i];

  return sum_of_top_k >= 0;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::cin >> n >> k;
  jewels.resize(n);

  for (int i = 0; i < n; ++i)
  {
    std::cin >> jewels[i].quality >> jewels[i].weight;
  }

  double low = 0.0;
  double high = 1000001.0;

  for (int i = 0; i < 100; ++i)
  {
    double mid = low + (high - low) / 2.0;
    if (check(mid))
      low = mid;
    else
      high = mid;
  }

  // Print the final answer with up to 10 decimal places for precision.
  std::cout << std::fixed << std::setprecision(10) << low << std::endl;

  return 0;
}