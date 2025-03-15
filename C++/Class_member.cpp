#include <bits/stdc++.h>
using namespace std;

class arbitrary
{
private:
  string name;
  int age;

public:
  arbitrary(string n, int a)
  {
    name = n;
    age = a;
  };

  void display()
  {
    cout << name << endl;
  }
};

int main()
{
  arbitrary a1("Alex", 10);
  a1.display();

  return 0;
}