#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll base = 1<<20;
ll tree[2 * base];
ll n, m;

void set_interval(ll beg, ll end, ll value = 0) {
  beg += base;
  end += base;
  while(beg <= end) {
    if(beg % 2)
      tree[beg] *= -1;
    if(!(end % 2))
      tree[end] *= -1;
    beg = (beg + 1) / 2;
    end = (end - 1) / 2;
  }
}

void query_point(ll vertex, ll answer = 1) {
  vertex += base;
  answer = tree[vertex];
  vertex /= 2;
  while(vertex) {
    answer *= tree[vertex];
    vertex /= 2;
  }
  if(answer == 1)
    cout << "ON\n";
  else
    cout << "OFF\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 2 * base; ++i)
    tree[i] = 1;
  cin >> n >> m;
  for(ll i = 1; i <= n; ++i) {
    char state;
    cin >> state;
    tree[base + i] = -1 + 2 * (state == 'o');
  }
  for(ll i = 0; i < m; ++i) {
    char action;
    ll a, b;
    cin >> action >> a;
    if(action == 'Q')
      query_point(a);
    else {
      cin >> b;
      set_interval(a, b);
    }
  }
}