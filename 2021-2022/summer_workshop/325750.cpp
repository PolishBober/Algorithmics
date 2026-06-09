#include <iostream>
using namespace std;
const int many = 20000000;
int prime[many];

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin >> t;
    for(long long i = 2; i < many + 1; ++i) {
        if(!prime[i]) {
            prime[i] = i;
            for(long long j = i*i; j < many; j += i)
                if(!prime[j])
                    prime[j] = i;
        }
    }
    for(int i = 0, number; i < t; ++i) {
        cin >> number;
        while(number != 1) {
            cout << prime[number] << " ";
            number /= prime[number];
        }
        cout << "\n";
    }
}