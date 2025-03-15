#include <bits/stdc++.h>
#include "Account.h"
using namespace std;

int main()
{
  account member("Alex");
  member.display();

  if (member.deposit(5101))
    member.display();
  else
    cout << "Deposit Failed!" << endl;

  if (member.deposit(-50))
    member.display();
  else
    cout << "Deposit Failed!" << endl;

  if (member.withdraw(-50))
    member.display();
  else
    cout << "Withdraw Failed!" << endl;

  if (member.withdraw(500))
    member.display();
  else
    cout << "Withdraw Failed!" << endl;

  return 0;
}