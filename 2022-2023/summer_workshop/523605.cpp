#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e6;
vector <ll> graph[2][maxn + 1];
bool available[2][maxn + 1];
vector <ll> post;
ll scc[maxn + 1];

void dfs(ll vertex, bool dimension, ll k = 0) {
  if(dimension)
    scc[vertex] = k;
  available[dimension][vertex] = true;
  for(auto edge : graph[dimension][vertex])
    if(!available[dimension][edge])
      dfs(edge, dimension, k);
  if(!dimension)
    post.push_back(vertex);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll a, b;
  for(ll i = 0; i < m ; ++i) {
    cin >> a >> b;
    graph[0][a].push_back(b);
    graph[1][b].push_back(a);
  }
  for(ll i = 1; i <= n; ++i) {
    if(!available[0][i])
      dfs(i, 0);
  }
  ll k = 0;
  for(ll i = n - 1; i >= 0; --i)
    if(!available[1][post[i]])
      dfs(post[i], 1, k++);
  ll q;
  cin >> q;
  for(ll i = 0; i < q; ++i) {
    cin >> a >> b;
    if(scc[a] == scc[b])
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}