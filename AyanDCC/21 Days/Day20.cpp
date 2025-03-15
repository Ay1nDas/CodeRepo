#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  std::srand(static_cast<unsigned>(std::time(0)));
  int friend_gathered = std::rand();
  std::cout << friend_gathered % 32 + 1 << std::endl;
}
