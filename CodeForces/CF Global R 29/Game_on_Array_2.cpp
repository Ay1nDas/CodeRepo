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
using JobType = std::pair<int, long long>;

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    map<int, int> counts;
    for (int i = 0; i < n; ++i)
    {
      int val;
      cin >> val;
      counts[val]++;
    }

    map<int, ll> aggregated_jobs;
    for (auto const &[val, count] : counts)
    {
      aggregated_jobs[count] += val;
    }

    vector<JobType> job_list;
    for (auto const &[count, total_duration] : aggregated_jobs)
    {
      job_list.push_back({count, total_duration});
    }

    sort(job_list.rbegin(), job_list.rend());

    ll alice_score = 0;
    ll bob_score = 0;
    bool is_alice_turn = true;

    for (const auto &job : job_list)
    {
      int c = job.first;
      ll v = job.second;

      ll num_alice_turns;
      ll num_bob_turns;

      if (is_alice_turn)
      {
        num_alice_turns = (v + 1) / 2;
        num_bob_turns = v / 2;
      }
      else
      {
        num_bob_turns = (v + 1) / 2;
        num_alice_turns = v / 2;
      }

      alice_score += num_alice_turns * c;
      bob_score += num_bob_turns * c;

      if (v % 2 != 0)
      {
        is_alice_turn = !is_alice_turn;
      }
    }

    cout << alice_score << " " << bob_score << endl;
  }

  return 0;
}