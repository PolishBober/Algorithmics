#include <bits/stdc++.h>
using namespace std;
const int base = 1<<20;
pair <long long, long long> tree[2 * base];

void add(int v, int x) {
    v += base;
    tree[v].first = x;
    v /= 2;
    while(v) {
        tree[v].first = max(tree[2 * v].first, tree[2 * v + 1].first);
        tree[v].second = min(tree[2 * v].first, tree[2 * v + 1].first) + tree[2 * v].second + tree[2 * v + 1].second;
        v /= 2;
    }
}

void query(int a, int b) {
    pair <long long, long long> answer = {0, 0};
    a += base - 1;
    b += base + 1;
    while(a / 2 != b / 2) {
        if(!(a % 2)) {
            answer.second = min(answer.first, tree[a + 1].first) + answer.second + tree[a + 1].second;
            answer.first = max(answer.first, tree[a + 1].first);
        }
        if(b % 2) {
            answer.second = min(answer.first, tree[b - 1].first) + answer.second + tree[b - 1].second;
            answer.first = max(answer.first, tree[b - 1].first);
        }
        a /= 2;
        b /= 2;
    }
    if(answer.first < answer.second)
        cout << "TAK" << "\n";
    else
        cout << "NIE" << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        add(i, x);
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        query(a - 1, b - 1);
    }
}