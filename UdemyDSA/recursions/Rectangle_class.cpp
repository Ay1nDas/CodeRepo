#include <iostream>
using namespace std;

class rectangle
{
private:
  int length;
  int breath;

public:
  rectangle(int l = 1, int b = 1)
  {
    length = l;
    breath = b;
  }
  void print_length()
  {
    cout << length << endl;
  }
};

int main()
{
  rectangle r1(10, 5);
  r1.print_length();

  // cout << r1.length << endl;
}
