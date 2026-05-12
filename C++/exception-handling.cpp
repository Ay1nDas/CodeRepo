#include <bits/stdc++.h>
using namespace std;

int main()
{
  int num = 0;
  try {
    if (num == 0) {
      throw 0;
    }
    cout << "Not Catch!" << endl;
  }
  catch (int &ex) {
    cout << "Catch!" << endl;
  }


  return 0;
}
