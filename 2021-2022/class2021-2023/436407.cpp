#include <bits/stdc++.h>
using namespace std;
const int maxprime = 1299709 + 1;
bool primes[maxprime];
vector <int> eratostenes;

void sieve(int range) {
    for(int i = 2; i < maxprime; ++i) {
        if(!primes[i]) {
            eratostenes.push_back(i);
            for(int j = 2 * i; j < maxprime; j += i)
                primes[j] = true;
        }
        if(eratostenes.size() >= range)
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    sieve(n);
    for(int i = 0; i < eratostenes.size(); ++i)
        cout << eratostenes[i] << " ";
}