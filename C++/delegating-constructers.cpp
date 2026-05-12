#include <bits/stdc++.h>
using namespace std;

class cls {
  int a, b, c;
public:
  cls(int a_val, int b_val, int c_val) : a(a_val), b(b_val), c(c_val) {
    cout << "Called with a = " << a << " b = " << b << " c = " << c << endl;
  } 
  cls(int a_val) : cls {a_val, 0.0, 0} {}
};

int main()
{
  cls c1(10);
  return 0;
}
