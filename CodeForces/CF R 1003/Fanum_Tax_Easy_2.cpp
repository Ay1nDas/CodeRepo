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
    int n, m, b;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a.at(i);
    cin >> b;

    vector <int> dup_a(n);
    for(int i=0; i<n; i++)
      dup_a.at(i) = b - a.at(i);

    bool isPossible = true;
    int pre_val = min(dup_a.at(0), a.at(0));
    // cout<<"Pre: "<<pre_val<<" ";
    for(int i=1; i<n; i++){
      if(min(dup_a.at(i), a.at(i))>=pre_val){
        pre_val = min(dup_a.at(i), a.at(i));
        // cout<<pre_val<<" ";
      }
      else if(max(dup_a.at(i), a.at(i))>=pre_val){
        pre_val = max(dup_a.at(i), a.at(i));
        // cout<<pre_val<<" ";
      }
      else{
        isPossible = false;
        break;
      }
    }
    cout << (isPossible ? "YES" : "NO") << endl;

  }

  return 0;
}