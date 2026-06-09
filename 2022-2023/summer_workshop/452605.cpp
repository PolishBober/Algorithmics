#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll id, weight;
  friend bool operator < (const Description & a, const Description & b) {
    return a.weight < b.weight;
  }
};

const ll maxn = 1e6;
vector <Description> graph[maxn + 1];
ll edges[maxn + 1];
ll distances[maxn + 1];
priority_queue <Description> todo;
ll n, m;

void toposort() {
  for(auto & distance : distances)
    distance = -1;
  for(ll i = 1; i <= n; ++i) {
    if(!edges[i]) {
      todo.push({i, 0});
      distances[i] = 0;
    }
  }
  while(!todo.empty()) {
    Description top = todo.top();
    todo.pop();
    if(top.weight < distances[top.id])
      continue;
    for(auto & edge : graph[top.id]) {
      if(distances[edge.id] < top.weight + edge.weight || distances[edge.id] < 0)
        distances[edge.id] = top.weight + edge.weight;
      --edges[edge.id];
      if(!edges[edge.id])
        todo.push({edge.id, distances[edge.id]});
    }
  }
  ll maxd = 0;
  for(ll i = 1; i <= n; ++i)
    if(maxd < distances[i] && maxd >= 0 || distances[i] == -1)
      maxd = distances[i];
  cout << maxd;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(ll i = 0; i < m; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    ++edges[b];
  }
  toposort();
}