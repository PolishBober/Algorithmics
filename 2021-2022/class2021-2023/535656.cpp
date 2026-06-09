#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
	ll id, weight;
	friend bool operator < (const Edge & a, const Edge & b) {
		return a.weight > b.weight;
	}
};

#define MAXN int(1e5 + 1)

vector <Edge> graph[MAXN];
ll distances1[MAXN];
ll distances2[MAXN];
priority_queue <Edge> todo;
ll n, m;

void dijkstra1(ll vertex) {
	for(auto &d : distances1)
		d = -1;
	distances1[vertex] = 0;
	todo.push({vertex, 0});
	while(!todo.empty()) {
		auto top = todo.top();
		todo.pop();
		if(distances1[top.id] < top.weight && distances1[top.id] != -1)
			continue;
		for(auto edge : graph[top.id]) {
			if(distances1[edge.id] > top.weight + edge.weight || distances1[edge.id] == -1) {
				distances1[edge.id] = top.weight + edge.weight;
				todo.push({edge.id, distances1[edge.id]});
			}
		}
	}
}

vector <ll> answer;

void dijkstra2(ll vertex, ll distance) {
	answer.push_back(n);
	for(auto &d : distances2)
		d = -1;
	distances2[vertex] = 0;
	todo.push({vertex, 0});
	while(!todo.empty()) {
		auto top = todo.top();
		todo.pop();
		if(distances2[top.id] < top.weight && distances2[top.id] != -1)
			continue;
		for(auto edge : graph[top.id]) {
			if(distances2[edge.id] > top.weight + edge.weight || distances2[edge.id] == -1) {
				distances2[edge.id] = top.weight + edge.weight;
				if(distances2[edge.id] + distances1[edge.id] == distance)
					answer.push_back(edge.id);
				todo.push({edge.id, distances2[edge.id]});
			}
		}
	}
	sort(answer.begin(), answer.end());
	for(auto a : answer)
		cout << a << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(ll i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	dijkstra1(1);

	dijkstra2(n, distances1[n]);

	return 0;
}