#include <iostream>
// #include <string>
using namespace std;

int main()
{

  int test_cases;
  cin >> test_cases;

  while (test_cases--)
  {
    int strSize;
    cin >> strSize;

    int count{1}, max_count{1};
    char pre_c;
    cin >> pre_c;

    for (int i = 1; i < strSize; i++)
    {
      char c;
      cin >> c;
      if (c != pre_c)
      {
        count++;
      }
      else
      {
        if (count > max_count)
          max_count = count;
        count = 1;
      }
      pre_c = c;
    }

    if (count > max_count)
      max_count = count;

    cout << max_count << endl;
  }

  return 0;
}
