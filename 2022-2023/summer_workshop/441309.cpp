#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll weight;
  ll id;
  friend bool operator < (const Description & a, const Description & b) {
    return a.weight > b.weight;
  }
};

const ll maxn = 5e5;
vector <Description> graph[maxn + 1];
ll distances[maxn + 1];
priority_queue <Description> todo;

void dijkstra(ll vertex) {
  for(auto & distance : distances)
    distance = -1;
  todo.push({0, vertex});
  distances[vertex] = 0;
  while(!todo.empty()) {
    Description top = todo.top();
    todo.pop();
    if(top.weight > distances[top.id])
      continue;
    for(auto edge : graph[top.id]) {
      if(distances[edge.id] > top.weight + edge.weight || distances[edge.id] < 0) {
        distances[edge.id] = top.weight + edge.weight;
        todo.push({distances[edge.id], edge.id});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll a, b, w;
  for(int i = 0; i < m; ++i) {
    cin >> a >> b >> w;
    graph[a].push_back({w, b});
    graph[b].push_back({w, a});
  }
  dijkstra(1);
  for(int i = 1; i <= n; ++i)
    cout << distances[i] << '\n';
}