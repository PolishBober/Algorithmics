#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
long long pref[maxn + 1][maxn + 1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> pref[i][j];
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }
  for(int i = 1; i <= n; ++i) {
    cout << pref[i][m] - pref[i - 1][m] << " ";
  }
  cout << "\n";
  for(int j = 1; j <= m; ++j) {
    cout << pref[n][j] - pref[n][j - 1] << " ";
  }
}