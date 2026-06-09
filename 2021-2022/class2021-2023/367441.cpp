#include <bits/stdc++.h>
using namespace std;
const int maxprime = 1e6;
bool composite[maxprime + 1];
int pref[maxprime + 1];

void sieve() {
    for(int i = 2; i <= maxprime; ++i)
        if(!composite[i])
            for(int j = 2 * i; j <= maxprime; j += i)
                composite[j] = true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    for(int i = 2; i <= maxprime; ++i)
        pref[i] = pref[i - 1] + !composite[i];
    int n;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
    }
}