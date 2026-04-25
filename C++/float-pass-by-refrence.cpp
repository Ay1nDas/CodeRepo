#include <bits/stdc++.h>
using namespace std;

void passFloat(float arr[2]) {
  arr[0] = 1;
  arr[1] = 2;
}

int main()
{
  float main_arr[2] = {-1, -1};
  passFloat(main_arr);

  cout << main_arr[0] << " " << main_arr[1] << endl;
  return 0;
}