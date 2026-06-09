#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e5;
const ll maxp = 17;
vector <ll> graph[maxn + 1];
ll pre[maxn + 1];
ll post[maxn + 1];
ll ancestors[maxn + 1][maxp];
ll time_;
ll n, q;

void dfs(ll vertex) {
  pre[vertex] = ++time_;
  for(ll i = 1; i < maxp; ++i)
    ancestors[vertex][i] = ancestors[ancestors[vertex][i - 1]][i - 1];
  for(auto edge : graph[vertex]) {
    if(!pre[edge]) {
      ancestors[edge][0] = vertex;
      dfs(edge);
    }
  }
  post[vertex] = ++time_;
}

bool heir(ll descendant, ll ancestor) {
  return pre[descendant] >= pre[ancestor] && post[descendant] <= post[ancestor];
}

ll lca(ll vertex1, ll vertex2) {
  if(heir(vertex1, vertex2))
    return vertex2;
  if(heir(vertex2, vertex1))
    return vertex1;
  for(ll i = maxp - 1; i >= 0; --i) {
    if(heir(vertex2, ancestors[vertex1][i]))
      continue;
    vertex1 = ancestors[vertex1][i];
  }
  return ancestors[vertex1][0];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ll a, b, c;
  for(ll i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(ll i = 0; i < maxn + 1; ++i)
    for(ll j = 0; j < maxp; ++j)
      ancestors[i][j] = 1;
  dfs(1);
  /*
  for(ll i = 1; i <= n; ++i) {
    for(ll j = 0; j < maxp; ++j)
      cout << ancestors[i][j] << ' ';
    cout << '\n';
  } */
  cin >> q;
  for(ll i = 0; i < q; ++i) {
    cin >> a >> b >> c;
    //cout << lca(a, b) << '\n';
    if(heir(c, lca(a,b)) && (heir(a, c) || heir(b, c)))
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}