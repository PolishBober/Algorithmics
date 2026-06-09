#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 2e5;
ll taverns[maxn + 1];

struct Edge {
	ll id, weight;
	ll lider;
	friend bool operator < (const Edge & edge1, const Edge & edge2) {
		if(edge1.weight == edge2.weight)
			return taverns[edge1.lider] > taverns[edge2.lider];
		return edge1.weight > edge2.weight;
	}
};

vector <Edge> graph[maxn + 1];
ll distances[maxn + 1];
ll answer[maxn + 1];
priority_queue <Edge> todo;
ll n, m, k;

void dijkstra() {
	while(!todo.empty()) {
		Edge top = todo.top();
		todo.pop();
		if(distances[top.id] < top.weight)
			continue;
		for(auto edge : graph[top.id]) {
			if(distances[edge.id] > top.weight + edge.weight || distances[edge.id] == top.weight + edge.weight && taverns[top.lider] < taverns[answer[edge.id]] || !answer[edge.id]) {
				distances[edge.id] = top.weight + edge.weight;
				answer[edge.id] = top.lider;
				todo.push({edge.id, distances[edge.id], top.lider});
			}
		}
	}
}


int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	cin >> n >> m >> k;
	for(ll i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[b].push_back({a, c});
	}
	for(ll i = 1; i <= k; ++i) {
		ll d;
		cin >> d;
		if(!taverns[d])
			taverns[d] = i;
		todo.push({d, 0, d});
		answer[d] = d;
	}

	dijkstra();
	for(ll i = 1; i <= n; ++i) {
		if(!answer[i])
			cout << -1 << ' ';
		else
			cout << answer[i] << ' ';
	}
}