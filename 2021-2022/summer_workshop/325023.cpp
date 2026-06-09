#include <iostream>
using namespace std;
const int many = 20000000;
bool prime[many];

int main() {
    prime[0] = true;
    int n;
    cin >> n;
    int primecount = 0;
    for(long long i = 2; i < many + 1; ++i) {
        if(!prime[i - 1]) {
            if(++primecount == n) {
                for(int j = 0; j < i; ++j)
                    if(!prime[j])
                        cout << j + 1 << "\n";
                return 0;
            }
            for(long long j = i*i; j < many; j += i)
                prime[j - 1] = true;
        }
    }
}