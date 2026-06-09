#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int pref[n + 1], number;
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> number;
        pref[i] = pref[i - 1] + number;
    }
    int a, b;
    for(int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
    }
}