#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6;
int tab[maxn + 1];
vector <int> dp;
ll n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(ll i = 1; i <= n; ++i) {
    ll help;
    cin >> help;
    tab[i] = help + i;
  }
  dp.push_back(tab[1]);
  for(ll i = 1; i <= n; ++i) {
    if(tab[i] < dp.back())
      dp.back() = tab[i];
    if(dp.back() < i)
      dp.push_back(tab[i]);
  }
  cout << dp.size() << '\n';
}