#include <iostream>
#include <string>
using namespace std;

int main()
{

  int test_cases;
  cin >> test_cases;

  while (test_cases--)
  {
    int strSize;
    cin >> strSize;

    string str;
    cin >> str;

    int count{1}, max_count{1};

    for (int i = 1; i < str.length(); i++)
    {
      if (str.at(i) != str.at(i - 1))
      {
        count++;
      }
      else
      {
        if (count > max_count)
          max_count = count;
        count = 1;
      }
    }

    if (count > max_count)
      max_count = count;

    cout << max_count << endl;
  }

  return 0;
}
