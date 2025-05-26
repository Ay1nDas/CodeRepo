#include <bits/stdc++.h>
using namespace std;

class opp
{
private:
  int a;
  int b;

public:
  opp(opp *, int, int);
  void display()
  {
    cout << a << " " << b << endl;
  }
};

opp::opp(opp *ptr, int a, int b)
{
  ptr->a = a;
  ptr->b = b;
}

int main()
{

  opp o(&o, 10, 12);
  o.display();

  return 0;
}
