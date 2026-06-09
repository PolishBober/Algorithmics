#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll base = 1 << 17;
ll tree[2 * base];
ll n, m;

void set_point(ll vertex, ll value) {
  vertex += base;
  tree[vertex] = value;
  vertex /= 2;
  while(vertex) {
    tree[vertex] = max(tree[2 * vertex], tree[2 * vertex + 1]);
    vertex /= 2;
  }
}

ll binsearch(ll value) {
  ll vertex = 1;
  while(vertex < base) {
    if(tree[2 * vertex] >= value)
      vertex *= 2;
    else if(tree[2 * vertex + 1] >= value)
      vertex = 2 * vertex + 1;
    else
      return base - 1;
  }
  return vertex;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(ll i = 1; i <= n; ++i) {
    ll d;
    cin >> d;
    set_point(i, d);
  }
  cin >> m;
  for(ll i = 1; i <= m; ++i) {
    ll a;
    cin >> a;
    ll help = binsearch(a);
    cout << help - base << ' ';
    if(help >= base)
      set_point(help - base, tree[help] - a);
  }
}