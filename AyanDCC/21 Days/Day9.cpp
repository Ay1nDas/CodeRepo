#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
  int test_cases{0};
  cin >> test_cases;

  while (test_cases--)
  {
    int n, k;
    cin >> n >> k;

    vector<int> insects(n);
    for (int i = 0; i < n; i++)
    {
      cin >> insects.at(i);
    }

    int l{0}, r{0};
    int insect_found{0};
    int min_dist{INT32_MAX};
    unordered_map<int, int> freq;
    while (r < n && l <= r)
    {
      while (r < n && insect_found < k)
      {
        if (freq[insects.at(r)] == 0)
          insect_found++;
        freq[insects.at(r)]++;
        r++;
      }
      if (insect_found == k && min_dist > r - l)
        min_dist = r - l;
      // cout << "r: " << r << endl
      //      << "l: " << l << endl;
      // cout << "Dist1: " << r - l << endl;

      while (l < n && insect_found >= k - 1)
      {
        if (freq[insects.at(l)] > 1)
          freq[insects.at(l)]--;
        else if (insect_found == k)
        {
          insect_found--;
          freq[insects.at(l)]--;
        }
        else if (insect_found == k - 1)
          break;
        l++;
      }
      // if (min_dist > r - l + 2)
      //   min_dist = r - l + 2;
      // cout << "r: " << r << endl
      //      << "l: " << l << endl;
      // cout << "Dist2: " << r - l + 2 << endl;
    }

    cout << min_dist << endl;
  }
}