#include <bits/stdc++.h>
using namespace std;

long long NWD(long long a, long long b) {
    if(b < a)
        swap(a, b);
    while(a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        long long nwd = NWD(a, b);
        b /= nwd;
        cout << a / nwd << " " << b / NWD(b, nwd)<< "\n";
    }
}