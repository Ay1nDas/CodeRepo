#include <iostream>
#include <string>
using namespace std;

int main()
{
  // === Constructors ===
  string s1 = "hello";
  string s2("world");
  string s3(5, 'a'); // "aaaaa"
  string s4 = s1;    // Copy constructor

  s1.size();   // Returns size       return type: size_t
  s1.length(); // Returns length     return type: size_t (same as .size())
  s1.empty();  // empty or not?      return type: bool
  s1.clear();  // empties the string return type: void

  s1 = "hello"; // Re-initialize s1

  // === Element Access ===
  cout << "\n--- Element Access ---" << endl;
  s1[0];           // 'h' NO bounds checking        return type: reference(char &)
  s1.at(1);        // 'e' Performs bounds checking  return type: reference(char &)
  s1.front();      // 'h' get front char            return type: reference(char &)
  s1.back();       // 'o' get back char             return type: reference(char &)
  s1.back() = 'O'; // Modify back() or front()      return type: reference(char &)
  s1.c_str();      // C style string                return type: char *;

  s1 += " " + s2;              // Appends the string s2 to s1.
  s1.append("!");              // Appends the string "!" to s1.
  s1.push_back('Z');           // Appends the single character 'Z' to s1.
  s1.pop_back();               // Removes the last character ('Z') from s1.
  s1.insert(6, "cruel ");      // Inserts string "cruel " at index 6 (0 indexed).
  s1.erase(6, 6);              // Erases 6 characters starting from index 6.
  s1.replace(0, 5, "goodbye"); // Replaces 5 chars, from index 0, with "goodbye".

  // === String Operations (Searching & Substrings) ===

  // Creates a new string of length 5 from s1 starting at index 10.
  // Complexity: O(K) (K is the length of the substring, 5 here)
  string sub = s1.substr(10, 5);

  // Finds the index of the first occurrence of "fox" in s1.
  // Complexity: O(N * M)
  size_t pos = s1.find("fox"); // string::npos is returned if not found

  // Finds the first occurrence of "the", starting the search from index 1.
  // Complexity: O(N * M)
  pos = s1.find("the", 1); // string::npos is returned if not found

  // Finds the index of the *last* occurrence of "o" in s1.
  // Complexity: O(N * M) (M=1 here)
  pos = s1.rfind("o"); // string::npos is returned if not found

  // Finds the first char in s1 that is 'a', 'e', 'i', 'o', or 'u'.
  // Returns the position of that in s1.
  // Complexity: O(N * M) (M is length of "aeiou")
  pos = s1.find_first_of("aeiou");

  // ---
  string s_num = "12345ABCDE";

  // Finds the first char in s_num that is NOT in "0123456789".
  // Complexity: O(N * M) (M is length of "0123456789")
  pos = s_num.find_first_not_of("0123456789");
  cout << "First non-digit in " << s_num << " at: " << pos << endl; // 5

  // compare
  string a = "apple";
  string b = "apply";

  // Checks if a is lexicographically (i.e., dictionary order) less than b.
  // Complexity: O(min(N, M))
  a < b; // true here

  // Checks if a is lexicographically equal to b.
  // Complexity: O(min(N, M))
  a == b; // false here

  // Checks if a is lexicographically greater than b. (false)
  // Complexity: O(min(N, M))
  a > b; // false here

  // Compares a and b. Returns < 0 if a < b. (true)
  // Complexity: O(min(N, M))
  a.compare(b) < 0; // true here

  // Compares a and b. Returns > 0 if a > b.
  // Complexity: O(min(N, M))
  a.compare(b) > 0; // false here

  // Compares a and "apple". Returns 0 if equal. (true)
  // Complexity: O(min(N, M))
  a.compare("apple") == 0; // false here

  return 0;
}