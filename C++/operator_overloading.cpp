#include <bits/stdc++.h>
using namespace std;

class cls {
public:
  int val;

  void operator+(int a) {
    std::cout << "int: " << a << "Val: " << val << std::endl;
  }

  operator float() {
    cout << "float Converstion!" << endl;

    return 0.0f;
  }

  cls(int a = 0) {
    cout << "Constructor: " << a << endl;
  }

  void operator=(int a) {
    cout << "Equal to : " << a << endl;
  }

  virtual void func() {
    cout << "Base" << endl;
  }
};

class derived : public cls {
public:
  void func() override {
    cout << "Derived" << endl;
  }
};

int main()
{
  cls c;
  c.val = 12;
  c + 10;
  static_cast<float>(c);
  c = 10;

  derived d;
  d.func();

  return 0;
}