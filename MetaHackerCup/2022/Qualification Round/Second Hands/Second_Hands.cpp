#include <bits/stdc++.h>
using namespace std;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int main()
{
  ifstream inputFile("second_hands_input.txt");
  ofstream outputFile("second_hands_output.txt");
  fast_io;
  int T;
  inputFile >> T;
  for (int t = 1; t <= T; t++)
  {
    int n, k;
    inputFile >> n >> k;

    vector<int> parts(n);
    for (auto &p : parts)
      inputFile >> p;

    bool isPoss = true;
    if (k * 2 < n)
      isPoss = false;

    unordered_map<int, int> partCnt;
    for (auto &p : parts)
    {
      partCnt[p]++;

      if (partCnt[p] > 2)
        isPoss = false;
    }

    outputFile << "Case #" << t << ": ";
    outputFile << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}