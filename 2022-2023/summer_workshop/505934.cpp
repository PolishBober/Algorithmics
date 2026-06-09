#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll a, b, weight, position;
};

const ll maxn = 1e6;
ll tab[maxn + 1];
Description graph[maxn + 1];
ll n, m;

ll Find(ll vertex) {
  if(tab[vertex] == vertex)
    return vertex;
  tab[vertex] = Find(tab[vertex]);
  return tab[vertex];
}

void Union(ll vertex1, ll vertex2) {
  tab[Find(vertex1)] = Find(vertex2);
}

bool comparison(Description a, Description b) {
  return a.weight < b.weight;
}

void mst() {
  sort(graph + 1, graph + m + 1, comparison);
  for(ll i = 1; i <= m; ++i) {
    if(Find(graph[i].a) != Find(graph[i].b)) {
      Union(graph[i].a, graph[i].b);
      cout << graph[i].position << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(ll i = 1; i <= m; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    graph[i] = {a, b, c, i};
    tab[i] = i;
  }
  mst();
  return 0;
}