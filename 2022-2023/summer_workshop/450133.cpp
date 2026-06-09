#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e5;
vector <ll> graph[maxn + 1];
bool available[maxn + 1];
ll distances[maxn + 1];
queue <ll> todo;
vector <ll> leaves;
ll n;

void dfs(ll vertex) {
  available[vertex] = true;
  ll sum = 0;
  for(auto edge : graph[vertex]) {
    if(!available[edge]) {
      dfs(edge);
      sum += distances[edge];
    }
  }
  distances[vertex] = sum + 1;
}


/*
void bfs(vector <ll> & vertexes) {
  for(auto & distance : distances)
    distance = -1;
  for(auto vertex : vertexes) {
    todo.push(vertex);
    distances[vertex] = 1;
  }
  while(!todo.empty()) {
    ll top = todo.front();
    todo.pop();
    for(auto edge : graph[top]) {
      if(distances[edge] >= distances[top] || distances[edge] < 0) {
        ll neighbors = 0;
        for(auto neighbor : graph[edge])
          if(distances[neighbor] < 0)
            ++neighbors;
        if(neighbors == 1)
          todo.push(edge);
        distances[edge] += 2 * (distances[edge] < 0) + distances[top];
      }
    }
  }
}
*/

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(ll i = 0; i < n - 1; ++i) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(1);
  ll answer = 1;
  for(ll i = 1; i <= n; ++i) {
    ll maxe = distances[i];
    for(auto edge : graph[i])
      if(maxe < distances[edge])
        maxe = distances[edge];
    bool help = true;
    for(auto edge : graph[i]) {
      if(distances[edge] == maxe) {
        if(n - distances[i] > n / 2)
          help = false;
      }
      else if(distances[edge] > n / 2)
        help = false;
    }
    if(help)
      if(graph[answer].size() < graph[i].size() || graph[answer].size() == graph[i].size() && answer > i)
        answer = i;
  }
  cout << answer << '\n' << graph[answer].size() << '\n';
}