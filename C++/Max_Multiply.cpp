#include <iostream>
using namespace std;

int main()
{
  for (int i = 0; i <= 50; i++)
  {
    cout << i << " X " << (100 - i) << " = " << i * (100 - i) << endl;
  }
  return 0;
}
