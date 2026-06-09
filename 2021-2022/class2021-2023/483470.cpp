#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e5;
vector <ll> graph[maxn + 1];
ll distances[maxn + 1];
queue <ll> todo;

void bfs(ll vertex) {
  for(auto & distance : distances)
    distance = -1;
  todo.push(vertex);
  distances[vertex] = 0;
  while(!todo.empty()) {
    ll top = todo.front();
    todo.pop();
    for(auto edge : graph[top]) {
      if(distances[edge] < 0) {
        distances[edge] = distances[top] + 1;
        todo.push(edge);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll a, b;
  for(ll i = 0; i < m; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bfs(1);
  for(int i = 1; i <= n; ++i)
    cout << distances[i] << '\n';
}
