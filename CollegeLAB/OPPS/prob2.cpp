#include <iostream>
using namespace std;

class Base {
public:
  int value;
  Base(int val = 0) {
    cout << "User Defined Constructor for Base!" << endl;
    value = val;
    cout << "Value is: " << value << endl;
  }
};

class Derived : public Base {
public:
  Derived(int val = 0) : Base(val) {
    cout << "User defined Constructor for Derived!" << endl;
    value = val;
    cout << "Value is: " << value << endl;
  }
};

int main()
{
  Base b1, b2(5);
  Derived d1, d2(15);

  return 0;
}
