#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  string answerString(string word, int numFriends)
  {
    int max_str_len = word.length() - numFriends + 1;
    char max_char = 'a' - 1;
    string return_str;

    for (int i = 0; i < word.length(); i++)
    {
      if (word.at(i) > max_char)
      {
        return_str = word.substr(i, max_str_len);
        max_char = word.at(i);
      }
      else if (word.at(i) == max_char)
      {
        string sub_str = word.substr(i, max_str_len);
        return_str = max(sub_str, return_str);
      }
    }
    return return_str;
  }
};

int main()
{
}