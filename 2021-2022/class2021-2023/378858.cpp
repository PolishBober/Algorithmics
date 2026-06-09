#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
long long pref[maxn + 1][maxn + 1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 2; i <= n; ++i)
    pref[i][0] -= INT_MAX;
  for(int i = 2; i <= m; ++i)
    pref[0][i] -= INT_MAX;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> pref[i][j];
      pref[i][j] += max(pref[i - 1][j], pref[i][j - 1]);
    }
  }
  cout << pref[n][m];
}