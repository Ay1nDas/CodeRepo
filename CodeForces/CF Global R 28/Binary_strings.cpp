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
    string binary;
    cin >> binary;

    if (binary.length() == 1)
    {
      cout << "1 1 1 1" << endl;
      continue;
    }

    int first_0;

    for (int i = 0; i < binary.length(); i++)
    {
      first_0 = i;
      if (binary.at(i) == '0')
        break;
    }

    int subArr_len = binary.length() - first_0;
    string max_xor = "0";
    int max_xor_index{-1};

    for (int i = 0; i < first_0; i++)
    {
      string sub_arr = binary.substr(i, subArr_len);
      string current_xor = binary;

      int bi_index = binary.length() - 1;
      int sub_index = sub_arr.length() - 1;

      while (sub_index >= 0)
      {
        // current_xor.at(bi_index) = ((binary.at(bi_index) - '0') ^ (sub_arr.at(sub_index) - '0')) + '0';

        if (binary.at(bi_index) == sub_arr.at(sub_index))
          current_xor.at(bi_index) = '0';
        else
          current_xor.at(bi_index) = '1';

        bi_index--;
        sub_index--;
      }
      // cout << current_xor << endl;

      if (current_xor > max_xor)
      {
        max_xor = current_xor;
        max_xor_index = i + 1;
      }
    }

    cout << "1 " << binary.length() << " " << max_xor_index << " "
         << max_xor_index + subArr_len - 1 << endl;
  }

  return 0;
}