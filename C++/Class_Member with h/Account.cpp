#include "Account.h"
#include <iostream>

account::account(std::string n)
{
  name = n;
}

bool account::deposit(int money)
{
  if (money > 0)
  {
    bal += money;
    return true;
  }
  else
  {
    return false;
  }
}
bool account::withdraw(int money)
{
  if (bal - money > 0 && money > 0)
  {
    bal -= money;
    return true;
  }
  else
    return false;
}

void account::display()
{
  std::cout << name << " has $" << bal << " in his Account." << std::endl;
}