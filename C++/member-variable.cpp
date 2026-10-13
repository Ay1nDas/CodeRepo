#include <bits/stdc++.h>
using namespace std;

class variableName {
public:
  variableName(int a, int b) {
    cout << a << " " << b << endl;
  }
};

class cls {
public:
  variableName var = variableName(10, 20);
};


int main()
{
  cls c;
  return 0;
}