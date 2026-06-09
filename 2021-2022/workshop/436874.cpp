#include <bits/stdc++.h>
using namespace std;
const int base = 1 << 17;
long long tree[2 * base];

void query(int v) {
    long long answer = 1;
    v += base;
    while(v) {
        answer = (answer * tree[v]) % (long long)(1e9 + 7);
        v /= 2;
    }
    cout << answer << "\n";
}

void add(int a, int b, int x) {
    a += base - 1;
    b += base + 1;
    while(a / 2 != b / 2) {
        if(!(a % 2))
            tree[a + 1] = (x * tree[a + 1]) % (long long)(1e9 + 7);
        if(b % 2)
            tree[b - 1] = (x * tree[b - 1]) % (long long)(1e9 + 7);
        a /= 2;
        b /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 2 * base; ++i)
        tree[i] = 1;
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int t, a, b, x;
        cin >> t >> a;
        if(t)
            query(a);
        else {
            cin >> b >> x;
            add(a, b, x);
        }
    }
}