#include <bits/stdc++.h>
using namespace std;

class user
{
public:
  void outputDetails()
  {
    cout << firstName << " " << lastName << " " << dob << endl;
  }
  void clearName()
  {
    firstName = "";
    lastName = "";
  }

  user();

private:
  string firstName, lastName, dob;
};

int main()
{
  user appUser;
  appUser.outputDetails();
  appUser.clearName();
  appUser.outputDetails();
  return 0;
}

user::user()
{
  cout << "Name: " << endl;
  cin >> firstName >> lastName;
  cout << "Dob: " << endl;
  cin >> dob;
}