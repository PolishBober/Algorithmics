#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll id, weight;
  friend bool operator < (const Description & a, const Description & b) {
    return a.weight > b.weight;
  }
};

const ll maxn = 5e3;
vector <Description> graph[2 * maxn + 1];
ll distances[2 * maxn + 1];
priority_queue <Description> todo;
ll costs[maxn + 1];
ll n, m;

void dijkstra(ll vertex) {
  for(auto & distance : distances)
    distance = -1;
  todo.push({vertex, 0});
  distances[vertex] = 0;
  while(!todo.empty()) {
    Description top = todo.top();
    todo.pop();
    if(top.weight > distances[top.id])
      continue;
    for(auto edge : graph[top.id]) {
      if(distances[edge.id] > top.weight + edge.weight || distances[edge.id] < 0) {
        distances[edge.id] = top.weight + edge.weight;
        todo.push({edge.id, distances[edge.id]});
      }
    }
  }
  cout << distances[n + 1] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(ll i = 1; i <= n; ++i)
    cin >> costs[i];
  cin >> m;
  graph[1].push_back({n + 1, costs[1] / 2});
  for(ll i = 0; i < m; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[a].push_back({n + a, costs[a] / 2});
    graph[n + a].push_back({n + b, c});
  }
  dijkstra(1);
}