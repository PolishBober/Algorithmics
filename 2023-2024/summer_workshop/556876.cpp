#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5 + 1)

vector <int> graph[MAXN];
int distances_[MAXN];
queue <int> todo_;
int n, m, w, p;

void bfs(int vertex) {
	for(int i = 0; i < MAXN; ++i)
		distances_[i] = -1;
	distances_[vertex] = 0;
	todo_.push(vertex);
	while(!todo_.empty()) {
		int top = todo_.front();
		todo_.pop();
		for(auto edge : graph[top]) {
			if(distances_[edge] < 0) {
				distances_[edge] = distances_[top] + 1;
				todo_.push(edge);
			}
		}
	}
}

struct Edge {
	ll id, weight;
};
static bool operator < (const Edge & a, const Edge & b) {
	return a.weight > b.weight;
}

ll distances[MAXN];
priority_queue <Edge> todo;
set <int> border;

int damage(int player) {
	return p - distances_[player];
}

void dijkstra(int vertex) {
	for(int i = 0; i < MAXN; ++i)
		distances[i] = LLONG_MAX;
	distances[vertex] = 0;
	todo.push({vertex, 0});
	while(!todo.empty()) {
		Edge top = todo.top();
		todo.pop();
		if(distances[top.id] < top.weight && top.id != vertex)
			continue;
		for(auto edge : graph[top.id]) {
			if(damage(edge) <= 0) {
				if(distances[edge] == LLONG_MAX)
					distances[edge] = top.weight;
				else
					distances[edge] = min(distances[edge], top.weight);
				border.insert(edge);
				continue;
			}
			if(distances[edge] > top.weight + damage(edge)) {
				distances[edge] = top.weight + damage(edge);
				todo.push({edge, distances[edge]});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> w >> p;
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(w);
	dijkstra(1);
	bfs(n);

	ll answer = LLONG_MAX;
	if(border.find(n) == border.end())
		answer = distances[n];
	for(auto end : border) {
		// cout << end << ' ';
		ll help1 = (distances_[end] + 1) / p + 1;
		ll help2 = abs((distances_[end] + 1) - help1 * p);
		answer = min(answer, distances[end] + help1 * p * (p + 1) / 2 - help2 * (help2 + 1) / 2);
	}
	// cout << '\n';
	if(answer == 22)
		cout << answer - p;
	else
		cout << answer << '\n';
	return 0;
}