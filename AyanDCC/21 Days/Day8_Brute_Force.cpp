#include <iostream>
#include <vector>
using namespace std;

int find_combinations(vector<int> &prime, int index, int k)
{
  if (index == prime.size())
  {
    return 1;
  }
  int combinations{0};

  combinations += find_combinations(prime, index + 1, k);

  int val = prime.at(index) + k;
  while (index < prime.size() && prime.at(index) < val)
    index++;

  combinations += find_combinations(prime, index, k);

  return combinations;
}

int main()
{

  int test_cases{0};
  cin >> test_cases;
  vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79};
  while (test_cases--)
  {
    int n{0}, k{0};
    cin >> n >> k;

    vector<int> reqd_prime;
    for (int i = 0; prime.at(i) <= n - k; i++)
      reqd_prime.push_back(prime.at(i));

    int index{0};
    int combinations = find_combinations(reqd_prime, index, k);

    cout << combinations << endl;
  }

  return 0;
}
