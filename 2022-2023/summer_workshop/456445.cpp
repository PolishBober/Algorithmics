#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  int id, weight;
  friend bool operator < (Description a, Description b) {
    return a.weight > b.weight;
  }
};

const int maxn = 1e5;
vector <int> graph[maxn + 1];
int weights[maxn + 1];
int distances[maxn + 1];
priority_queue <Description> todo;
ll n, m;

void dijkstra(int vertex) {
  for(auto & distance : distances)
    distance = -1;
  todo.push({vertex, weights[vertex]});
  distances[vertex] = weights[vertex];
  while(!todo.empty()) {
    Description top = todo.top();
    todo.pop();
    if(distances[top.id] < top.weight)
      continue;
    for(auto edge : graph[top.id]) {
      if(distances[edge] > max(top.weight, weights[edge]) || distances[edge] < 0) {
        distances[edge] = max(top.weight, weights[edge]);
        todo.push({edge, distances[edge]});
      }
    }
  }
  cout << distances[n] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    cin >> weights[i];
  for(int i = 0; i < m; ++i) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dijkstra(1);
}