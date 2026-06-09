#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll base = 1<<20;
ll tree[2 * base];
ll tab[base];

void set_point(ll vertex, ll value) {
  vertex += base;
  tree[vertex] = value;
  vertex /= 2;
  while(vertex) {
    tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
    vertex /= 2;
  }
}

void query_interval(ll beg, ll end, ll answer = 0) {
  beg += base;
  end += base;
  while(beg <= end) {
    if(beg % 2)
      answer += tree[beg];
    if(!(end % 2))
      answer += tree[end];
    beg = (beg + 1) / 2;
    end = (end - 1) / 2;
  }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, q;
  cin >> n >> q;
  for(ll i = 1; i <= n; ++i) {
    cin >> tab[i];
    set_point(tab[i], tree[base + tab[i]] + 1);
  }
  for(ll i = 0; i < q; ++i) {
    string type;
    ll a, b;
    cin >> type >> a;
    if(type == "pyt")
      query_interval(a, base);
    else {
      cin >> b;
      set_point(tab[a], tree[base + tab[a]] - 1);
      set_point(b, tree[base + b] + 1);
      tab[a] = b;
    }
  }
}