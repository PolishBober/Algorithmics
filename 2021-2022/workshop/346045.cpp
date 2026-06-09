#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
int stain[maxn + 1][maxn + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int tab1[n], tab2[n];
    for(int i = 0; i < q; ++i) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        stain[y1][x1]++;
        stain[y1][x2 + 1]--;
        stain[y2 + 1][x1]--;
        stain[y2 + 1][x2 + 1]++;
    }
    for(int y = 1; y <= n; ++y) {
        for(int x = 1; x <= m; ++x) {
            stain[y][x] += stain[y][x - 1] + stain[y - 1][x] - stain[y - 1][x - 1];
            cout << stain[y][x] << " ";
        }
        cout << "\n";
    }
}