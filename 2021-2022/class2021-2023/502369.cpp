#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5) + 1

vector <ll> graph[MAXN];
ll edges[MAXN];
priority_queue <ll> todo;
vector <ll> answer;
ll n, m;

void toposort() {
	for(ll i = 1; i <= n; ++i)
		if(!edges[i])
			todo.push(-i);
	while(!todo.empty()) {
		auto top = -todo.top();
		todo.pop();
		answer.push_back(top);
		for(auto edge : graph[top]) {
			--edges[edge];
			if(!edges[edge])
				todo.push(-edge);
		}
	}
	if(answer.size() == n) {
		cout << "TAK\n";
		for(auto a : answer)
			cout << a << ' ';
	}
	else
		cout << "NIE";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		++edges[b];
	}

	toposort();

	return 0;
}