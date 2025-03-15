#include <iostream>
using namespace std;

int main()
{
  cout << ((1 | 2 | 4 | 8) | 1) << endl
       << (2 | 4 | 8) << endl;
  return 0;
}