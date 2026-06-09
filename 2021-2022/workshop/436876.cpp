#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll base = 1 << 17;
ll tree[2 * base];

void set_point(ll vertex, ll value) {
  vertex += base;
  tree[vertex] = value;
  vertex /= 2;
  while(vertex) {
    tree[vertex] = max(tree[2 * vertex], tree[2 * vertex + 1]);
    vertex /= 2;
  }
}

void query_interval(ll beg, ll end, ll answer = 0) {
  beg += base;
  end += base;
  while(beg <= end) {
    if(beg % 2)
      answer = max(tree[beg], answer);
    if(!(end % 2))
      answer = max(tree[end], answer);
    beg = (beg + 1) / 2;
    end = (end - 1) / 2;
  }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll q;
  cin >> q;
  ll t, a, b;
  for(ll i = 0; i < q; ++i) {
    cin >> t >> a >> b;
    if(t)
      query_interval(a, b);
    else
      set_point(a, b);
  }
}