#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long a = 1, b = n + 1;
    while(a - b) {
        long long between = (a + b) / 2;
        if(between <= sqrt(n))
            a = between + 1;
        else
            b = between;
    }
    cout << a;
}