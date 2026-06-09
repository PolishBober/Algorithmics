#include <bits/stdc++.h>
using namespace std;
const int base = 1<<20;
int tree[2 * base];

void add(int v, int x) {
    v += base;
    tree[v] = x;
    v /= 2;
    while(v) {
        tree[v] = tree[2 * v] ^ tree[2 * v + 1];
        v /= 2;
    }
}

void query(int a, int b) {
    int answer = 0;
    a += base - 1;
    b += base + 1;
    while(a / 2 != b / 2) {
        if(!(a % 2))
            answer ^= tree[a + 1];
        if(b % 2)
            answer ^= tree[b - 1];
        a /= 2;
        b /= 2;
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(i, x);
    }
    for(int i = 0; i < q; ++i) {
        string type;
        int a, b;
        cin >> type >> a >> b;
        a--;
        b--;
        if(type == "zamien") {
            int help = tree[base + a];
            add(a, tree[base + b]);
            add(b, help);
        }
        else
            query(a, b);
    }
}