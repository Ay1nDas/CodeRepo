#include <iostream>
using namespace std;

class Cls {
private:
  int data;
  void setData() {
    cout << "Enter your data: ";
    cin >> data;
  }
  void showData() {
    cout << "Your data is: " << data << endl;
  }

public:
  void dataOps() {
    setData();
    showData();
  }
};

int main()
{
  Cls c;
  c.dataOps();
  return 0;
}
