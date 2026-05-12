#include <bits/stdc++.h>
using namespace std;

class Player {
public:
  static int cnt;
  int player;
  static int get_player_count() {
    return cnt;
  }
};

int Player::cnt = 0;

int main()
{
  cout << Player::get_player_count() << endl;
  return 0;
}