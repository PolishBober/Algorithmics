#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int pref[maxn + 1][maxn + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int number;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> number;
            pref[i][j] = number + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    int a1, b1, a2, b2;
    for(int i = 0; i < q; ++i) {
        cin >> a1 >> b1 >> a2 >> b2;
        cout << pref[a2][b2] - pref[a2][b1 - 1] - pref[a1 - 1][b2] + pref[a1 - 1][b1 - 1] << "\n";
    }
}