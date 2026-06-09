#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5)

vector <ll> graph[3 * MAXN + 1];
ll distances[3 * MAXN + 1];
queue <ll> todo;
ll n, m, s, k;

void bfs(ll start, ll end) {
	for(auto & d : distances)
		d = -1;
	todo.push(start);
	distances[start] = 0;
	while(!todo.empty()) {
		auto top = todo.front();
		todo.pop();
		for(auto edge : graph[top]) {
			if(distances[edge] == -1) {
				distances[edge] = distances[top] + 1;
				todo.push(edge);
			}
		}
	}
	if(max(distances[end], max(distances[end + MAXN] - 1, distances[end + 2 * 	MAXN] - 2)) == -1)
		cout << -1;
	else {
		ll minimum = INT_MAX;
		if(distances[end] != -1)
			minimum = distances[end];
		if(distances[end + MAXN] != -1)
			minimum = min(minimum, distances[end + MAXN] - 1);
		if(distances[end + 2 * MAXN] != -1)
			minimum = min(minimum, distances[end + 2 * MAXN] - 2);
		cout << minimum;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s >> k;
	for(ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[a].push_back(a + MAXN);
		graph[b].push_back(b + MAXN);
		graph[b + MAXN].push_back(a + MAXN);
		graph[a + MAXN].push_back(a + 2 * MAXN);
		graph[b + MAXN].push_back(b + 2 * MAXN);
		graph[a + 2 * MAXN].push_back(b + 2 * MAXN);
	}

	bfs(s, k);

	return 0;
}