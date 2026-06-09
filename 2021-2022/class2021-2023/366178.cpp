#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string trees;
    cin >> trees;
    int brich[trees.size() + 1];
    brich[0] = 0;
    for(int i = 1; i < trees.size() + 1; ++i)
        brich[i] = brich[i - 1] + (trees[i - 1] == 'b');
    int q, a, b;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << brich[b] - brich[a - 1] << "\n";
    }
}