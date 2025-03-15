#include <bits/stdc++.h>
using namespace std;

void printCombinations(int n, int start, int end)
{
  std::vector<int> nums;
  for (int i = 0; i <= 25; ++i)
  {
    nums.push_back(i);
  }

  std::vector<bool> select(nums.size(), false);
  std::fill(select.begin(), select.begin() + n, true);

  do
  {
    for (size_t i = 0; i < nums.size(); ++i)
    {
      if (select[i])
      {
        std::cout << nums[i] << " ";
      }
    }
    std::cout << "\n";
  } while (std::prev_permutation(select.begin(), select.end()));
}

int main()
{
  int n = 3; // Change n as needed
  printCombinations(n, 0, 25);
  return 0;
}