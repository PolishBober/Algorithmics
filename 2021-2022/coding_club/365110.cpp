#include <bits/stdc++.h>
using namespace std;
const int base = 1<<20;
int tree[2 * base];

void query(int v) {
    v += base;
    int answer = tree[v];
    v /= 2;
    while(v) {
        answer *= tree[v];
        v /= 2;
    }
    if(answer == 1)
        cout << "ON\n";
    else
        cout << "OFF\n";
}

void add(int a, int b) {
    a += base - 1;
    b += base + 1;
    while(a / 2 != b / 2) {
        if(!(a % 2))
            tree[a + 1] *= -1;
        if(b % 2)
            tree[b - 1] *= -1;
        a /= 2;
        b /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 2 * base; ++i)
        tree[i] = 1;
    int n, m;
    cin >> n >> m;
    string lamps;
    cin >> lamps;
    for(int i = 0; i < n; ++i) {
        if(lamps[i] == 'o')
            tree[base + i] = 1;
        else
            tree[base + i] = -1;
    }
    for(int i = 0; i < m; ++i) {
        char type;
        cin >> type;
        if(type == 'Q') {
            int v;
            cin >> v;
            query(v - 1);
        }
        else {
            int a, b;
            cin >> a >> b;
            add(a - 1, b - 1);
        }
    }
}