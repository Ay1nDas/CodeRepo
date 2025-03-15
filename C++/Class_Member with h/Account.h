#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include <iostream>

class account
{
private:
  int bal = 0;
  std::string name;

public:
  account(std::string n);
  bool deposit(int money);
  bool withdraw(int money);
  void display();
};

#endif
