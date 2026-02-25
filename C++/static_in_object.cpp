#include <bits/stdc++.h>
using namespace std;

struct s {
  static int a;
};

int s::a = 10;

int main()
{
  struct s st1, st2;
  st1.a = 10;
  cout << st2.a;
  return 0;
}