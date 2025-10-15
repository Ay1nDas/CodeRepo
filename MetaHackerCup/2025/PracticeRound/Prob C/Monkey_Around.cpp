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
  ifstream inputFile("monkey_around_input.txt");
  ofstream outputFile("monkey_around_output.txt");

  fast_io;
  int T;
  inputFile >> T;

  for (int t = 1; t <= T; t++)
  {
    int n;
    inputFile >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
      inputFile >> arr.at(i);
    }

    unordered_map<int, int> freq;
    vector<vector<int>> partArr;
    freq[arr.at(0)]++;
    partArr.push_back({arr.at(0)});

    for (int i = 1; i < n; i++)
    {
      if (freq[arr.at(i)] == 1 || (abs(arr.at(i) - arr.at(i - 1)) != 1 && arr.at(i) != 1))
      {
        partArr.push_back({});
        freq.clear();
      }

      freq[arr.at(i)]++;
      partArr.back().push_back(arr.at(i));
    }

    // for (auto vec : partArr)
    // {
    //   for (auto i : vec)
    //   {
    //     cout << i << " ";
    //   }
    //   cout << endl;
    // }

    vector<ll> ops(partArr.size() + 1);
    ops.at(partArr.size()) = 0;

    for (int i = partArr.size() - 1; i >= 0; i--)
    {
      ops.at(i) = partArr.at(i).at(0) - 1;

      if (ops.at(i) < ops.at(i + 1))
      {
        ll multiplier = ((ops.at(i + 1) - ops.at(i)) / partArr.at(i).size());
        if ((ops.at(i + 1) - ops.at(i)) % partArr.at(i).size() != 0)
          multiplier++;

        ops.at(i) += multiplier * partArr.at(i).size();
      }
    }

    ll twoCnt = 0;

    for (int i = 0; i < ops.size() - 1; i++)
    {
      twoCnt += ops.at(i) - ops.at(i + 1);
    }

    outputFile << "Case #" << t << ": " << twoCnt + partArr.size() << endl;
    for (int i = 0; i < partArr.size(); i++)
    {
      outputFile << 1 << " " << partArr.at(i).size() << endl;
      for (int j = 0; j < ops.at(i) - ops.at(i + 1); j++)
      {
        outputFile << 2 << endl;
      }
    }
  }

  return 0;
}