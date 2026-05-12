#include <bits/stdc++.h>
using namespace std;

class Distance {
    int meter;
public:
    Distance(int m) {
        meter = m;
    }

    operator int() {
        return meter;
    }
};

int main() {
    Distance d(50);

    // int x = d;

    cout << (int)2.5f;
}
