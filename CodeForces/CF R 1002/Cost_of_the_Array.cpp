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
  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums.at(i);

    int b_index = 1;
    int partition = 1;
    int first_unequal_index = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      int num = nums.at(i);

      if (partition % 2 == 1)
      {
        partition++;
        k--;
        continue;
      }
      else if (num == b_index && k < n - i)
      {
        continue;
      }
      else if (num == b_index)
      {
        if (i + 1 != partition)
        {
          i = partition - 1;
          b_index++;
          if (nums.at(partition) == b_index) // Check overflow.
            partition++;
          else
          {
            break;
          }
          continue;
        }

        for (int j = i; j < n; j += 2)
        {
          if (nums.at(j) == b_index)
          {
            b_index++;
          }
          else
          {
            break;
          }
        }
        break;
      }
      else if (num != b_index)
      {
        first_unequal_index = b_index;
        break;
      }
    }

    cout << b_index << endl;
  }

  return 0;
}