#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
	ll id, weight;
	friend bool operator < (const Edge a, const Edge b) {
		return a.weight > b.weight;
	}
};

#define MAXN int(5e3 + 1)
#define MAXM int(1e5 + 1)

vector <Edge> graph[2 * MAXN];
ll distances[2 * MAXN];
priority_queue <Edge> todo;
ll n, m;

void dijkstra(ll vertex) {
	for(auto& d : distances)
		d = -1;
	distances[vertex] = 0;
	todo.push({vertex, 0});
	while(!todo.empty()) {
		auto top = todo.top();
		todo.pop();
		if(distances[top.id] < top.weight && distances[top.id] != -1)
			continue;
		for(auto edge : graph[top.id]) {
			if(distances[edge.id] > top.weight + edge.weight || distances[edge.id] == -1) {
				distances[edge.id] = top.weight + edge.weight;
				todo.push({edge.id, distances[edge.id]});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i) {
		ll a;
		cin >> a;
		graph[i].push_back({i + MAXN, a / 2});
	}

	cin >> m;
	for(ll i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[a + MAXN].push_back({b + MAXN, c});
	}

	dijkstra(1);

	cout << distances[MAXN + 1];

	return 0;
}