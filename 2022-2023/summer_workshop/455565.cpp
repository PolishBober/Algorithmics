#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll id, weight;
};

const ll maxn = 1e5;
vector <Description> graph[maxn + 1];
ll distances[maxn + 1];
ll n, v, q;

void dfs(ll vertex, ll value) {
  distances[vertex] = value;
  for(auto edge : graph[vertex])
    if(distances[edge.id] < 0)
      dfs(edge.id, value ^ edge.weight);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> v >> q;
  for(ll i = 0; i < n - 1; ++i) {
    ll a, b, x;
    cin >> a >> b >> x;
    graph[a].push_back({b, x});
    graph[b].push_back({a, x});
  }
  for(auto & d : distances)
    d = -1;
  dfs(1, 0);
  for(ll i = 0; i < q; ++i) {
    ll x, y;
    cin >> x >> y;
    cout << (ll)(distances[x] ^ distances[y] ^ v) << '\n';
  }
}