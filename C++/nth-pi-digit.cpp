#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int getNthDigitOfPi(int N) {
    int compute_count = N + 5; 
    
    int len = (10 * compute_count) / 3 + 1;
    std::vector<int> a(len, 2);
    
    std::vector<int> digits;
    
    int nines = 0;
    int predigit = 0;

    for (int j = 1; j <= compute_count; ++j) {
        int q = 0;
        
        for (int i = len; i > 0; --i) {
            int x = 10 * a[i - 1] + q * i;
            a[i - 1] = x % (2 * i - 1);
            q = x / (2 * i - 1);
        }
        
        a[0] = q % 10;
        q = q / 10;
        
        if (q == 9) {
            nines++;
        } else if (q == 10) {
            digits.push_back(predigit + 1);
            for (int k = 0; k < nines; ++k) {
                digits.push_back(0);
            }
            predigit = 0;
            nines = 0;
        } else {
            if (j > 1) { 
                digits.push_back(predigit);
            }
            predigit = q;
            for (int k = 0; k < nines; ++k) {
                digits.push_back(9);
            }
            nines = 0;
        }
    }
    
    digits.push_back(predigit); 

    if (N < digits.size()) {
        return digits[N];
    }
    
    return -1;
}

int main() {
  fast_io;
  int N;
  std::cin >> N;
  std::cout << getNthDigitOfPi(N) << "\n";
  
  return 0;
}
