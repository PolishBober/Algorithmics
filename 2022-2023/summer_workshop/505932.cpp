#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll id, weight;
};

struct Coordinates {
  ll y, x;
  bool checked = false;
};

const ll maxn = 5e3;
Coordinates positions[maxn];
ll mind[maxn];
queue <ll> todo;
ll n;

ll ceiling(double x) {
  return (ll)(x) + ((ll)(x) < x);
}

ll pitagoras(Coordinates a, Coordinates b) {
  return ceiling(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

void mst() {
  for(auto & m : mind)
    m = -1;
  ll vertex = 0;
  positions[vertex].checked = true;
  ll lenght = 0;
  for(ll i = 0; i < n - 1; ++i) {
    for(ll j = 0; j < n; ++j)
      if(!positions[j].checked && (pitagoras(positions[j], positions[mind[j]]) > pitagoras(positions[j], positions[vertex]) || mind[j] < 0))
        mind[j] = vertex;
    for(ll j = 0; j < n; ++j)
      if(!positions[j].checked && (positions[vertex].checked || pitagoras(positions[vertex], positions[mind[vertex]]) > pitagoras(positions[j], positions[mind[j]])))
        vertex = j;
    if(lenght < pitagoras(positions[vertex], positions[mind[vertex]]))
      lenght = pitagoras(positions[vertex], positions[mind[vertex]]);
    positions[vertex].checked = true;
  }
  cout << (n - 1) * lenght << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(ll i = 0; i < n; ++i) {
    ll y, x;
    cin >> y >> x;
    positions[i] = {y, x};
  }
  mst();
}