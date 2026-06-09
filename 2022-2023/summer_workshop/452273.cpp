#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e5;
vector <ll> graph[maxn + 1];
ll distances[maxn + 1];
vector <ll> todo;
ll n, m;

void toposort() {
  for(ll i = 1; i <= n; ++i)
    if(!distances[i])
      todo.push_back(i);
  if(todo.size() != 1) {
    cout << "NIE\n";
    exit(0);
  }
  ll index = 0;
  while(index < todo.size()) {
    ll top = todo[index++];
    ll pushes = 0;
    for(auto & edge : graph[top]) {
      --distances[edge];
      if(!distances[edge]) {
        todo.push_back(edge);
        ++pushes;
      }
    }
    if(pushes > 1) {
      cout << "NIE\n";
      exit(0);
    }
  }
  if(todo.size() < n)
    cout << "NIE\n";
  else {
    cout << "TAK\n";
    for(ll i = 0; i < n; ++i)
      cout << todo[i] << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(ll i = 0; i < m; ++i) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    ++distances[b];
  }
  toposort();
}