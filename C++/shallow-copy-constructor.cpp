#include <bits/stdc++.h>
using namespace std;

class Cls {
public:
  int *val;
  Cls(int n) {
    cout << "Constructor Called! " << n << endl;
    val = new int(n);
  }

  Cls(const Cls& c) : Cls(*c.val) {
    cout << "Copy Const Called!" << endl;
    // val = c.val; // -> Shallow Copy.
  }

  ~Cls() {
    delete val;
    cout << "Deleted" << endl;
  }
};

void func(Cls& c) {
  Cls cpy_c = c;
}

int main()
{
  Cls c(10);
  cout << *c.val << endl;
  func(c);
  cout << *c.val << endl;
  return 0;
}
