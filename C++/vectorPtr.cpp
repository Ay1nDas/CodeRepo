#include <bits/stdc++.h>
using namespace std;

void displayVec(vector<int> *vec)
{
  for(int i=0; i< vec->size(); i++)
  {
    cout<< vec->at(i) << " ";
  }
  cout<<endl;
} 

int main()
{
  vector<int> vec {1, 2, 3, 4, 5, 6, 7};
  displayVec(&vec);
  return 0;
}