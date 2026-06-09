#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
bool available[maxn + 1];
vector <int> graph[maxn + 1];

void dfs(int vertex) {
  available[vertex] = true;
  for(int edge : graph[vertex])
    if(!available[edge])
      dfs(edge);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int a, b;
  for(int i = 0; i < m; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs(1);
  for(int i = 1; i <= n; ++i) {
    if(available[i])
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
