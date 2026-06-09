#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
long long forest[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int y = 0; y < n; ++y)
        for(int x = 0; x < n; ++x)
            cin >> forest[y][x];
    for(int y = n - 1; y >= 0; --y) {
        for(int x = n - 1; x >= 0; --x) {
            forest[y][x] += max(forest[y + 1][x], forest[y][x + 1]);
        }
    }
    cout << forest[0][0];
}