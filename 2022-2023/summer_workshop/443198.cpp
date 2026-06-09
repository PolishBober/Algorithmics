#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll id, weight, origin;
  friend bool operator < (const Description & a, const Description & b) {
    return a.weight > b.weight;
  }
};

struct Distances {
  ll distance, origin;
};

ll u, n, m;
vector <ll> participants;
const ll maxn = 1e5;
vector <Description> graph[maxn + 1];
Distances distances[maxn + 1];
priority_queue <Description> todo;
ll answer = LONG_MAX;
ll duplication[maxn];

void dijkstra() {
  for(auto & distance : distances)
    distance.distance = -1;
  for(auto participant : participants) {
    todo.push({participant, 0, participant});
    distances[participant].distance = 0;
    distances[participant].origin = participant;
  }
  while(!todo.empty()) {
    Description top = todo.top();
    todo.pop();
    if(top.weight > distances[top.id].distance)
      continue;
    for(auto edge : graph[top.id]) {
      if(distances[edge.id].distance > top.weight + edge.weight || distances[edge.id].distance < 0) {
        distances[edge.id] = {top.weight + edge.weight, top.origin};
        todo.push({edge.id, distances[edge.id].distance, top.origin});
      }
      else if(top.origin != distances[edge.id].origin)
        if((top.weight + distances[edge.id].distance + edge.weight) * 3 < answer)
          answer = (top.weight + distances[edge.id].distance + edge.weight) * 3;
    }
  }
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> u >> n >> m;
  for(ll i = 0; i < u; ++i) {
    ll help;
    cin >> help;
    participants.push_back(help);
  }
  for(ll i = 0; i < m; ++i) {
    ll x, y, d;
    cin >> x >> y >> d;
    graph[x].push_back({y, d});
    graph[y].push_back({x, d});
  }
  for(auto participant : participants) {
    ++duplication[participant];
    if(duplication[participant] > 1) {
      cout << 0 << '\n';
      return 0;
    }
  }
  dijkstra();
}