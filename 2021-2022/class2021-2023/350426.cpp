#include <bits/stdc++.h>
using namespace std;

int nwd(long long a, long long b) {
    if(a > b)
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
    int q;
    cin >> q;
    long long a, b, c, d;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b >> c >> d;
        long long nww = b * d / nwd(b, d);
        a *= nww / b;
        c *= nww / d;
        long long divisor = nwd(a + c, nww);
        cout << (a + c) / divisor << " " << nww / divisor << "\n";
    }
}