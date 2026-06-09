#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int base = 1<<20;

ll tree[2 * base];
ll n, m, q;
vector <ll> tab;

void set_point(ll vertex, ll value) {
  vertex += base;
  tree[vertex] = value % m;
  vertex /= 2;
  while(vertex) {
    tree[vertex] = (tree[2 * vertex] * tree[2 * vertex + 1]) % m;
    vertex /= 2;
  }
}

ll query_interval(ll beg, ll end, ll answer = 1) {
  beg += base;
  end += base;
  while(beg <= end) {
    if(beg % 2)
      answer = (answer * (tree[beg] % m)) % m;
    if(!(end % 2))
      answer = (answer * (tree[end] % m)) % m;
    beg = (beg + 1) / 2;
    end = (end - 1) / 2;
  }
  return answer;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

for(ll i = 0; i < 2 * base; ++i)
  tree[i] = 1;

  cin >> n >> m >> q;
  for(ll i = 1; i <= n; ++i) {
    ll a;
    cin >> a;
    set_point(i, a);
  }
  for(ll i = 0; i < q; ++i) {
    ll c;
    cin >> c;
    if(c) {
      ll k;
      cin >> k;
      tab.clear();
      tab.push_back(0);
      for(ll j = 0; j < k; ++j) {
        ll help;
        cin >> help;
        tab.push_back(help);
      }
      tab.push_back(n + 1);
      sort(tab.begin(), tab.end());
      ll answer = 1;
      for(ll j = 1; j < tab.size(); ++j)
        answer = (answer * (query_interval(tab[j - 1] + 1, tab[j] - 1) % m)) % m;
      cout << answer << '\n';
    }
    else {
      ll p, w;
      cin >> p >> w;
      set_point(p, w);
    }
  }
}