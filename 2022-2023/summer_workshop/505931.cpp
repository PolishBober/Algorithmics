#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll id, weight;
};

const ll maxn = 5e5;
vector <Description> graph[maxn + 1];
bool available[maxn + 1];
ll booths[maxn];
ll n, m, k;
ll repeat[maxn + 1];


void dfs(ll vertex, ll time) {
  available[vertex] = true;
  for(auto edge : graph[vertex]) {
    if(!available[edge.id] && edge.weight > time) {
      dfs(edge.id, time);
    }
  }
}

bool condition(ll mid) {
  ll answer = 0;
  for(auto & a : available)
    a = false;
  dfs(booths[0], mid);
  for(ll i = 0; i < k; ++i)
    if(available[booths[i]])
      ++answer;
  return answer == k;
}

void binsearch() {
  ll beg = -1, end = 1e9 + 1;
  while(end - beg > 1) {
    ll mid = (beg + end) / 2;
    if(condition(mid))
      beg = mid;
    else
      end = mid;
  }
  cout << beg << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(ll i = 0; i < k; ++i) {
    ll help;
    cin >> help;
    booths[i] = help;
    ++repeat[help];
    if(repeat[help] > 1 || k == 1) {
      cout << "KEEP CALM AND FOLLOW THE WHITE RABBIT\n";
      return 0;
    }
  }
  for(ll i = 0; i < m; ++i) {
    ll a, b, t;
    cin >> a >> b >> t;
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
  }
  binsearch();
}