#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e6;
vector <ll> graph[maxn + 1];
ll n;
ll distances[maxn + 1];
ll deep;

void dfs(ll vertex) {
	for(auto edge : graph[vertex]) {
		if(distances[edge] == -1) {
			distances[edge] = distances[vertex] + 1;
			if(distances[edge] > distances[deep])
				deep = edge;
			dfs(edge);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n - 1; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(auto & d : distances)
		d = -1;
	distances[1] = 0;
	dfs(1);
	for(auto & d : distances)
		d = -1;
	distances[deep] = 0;
	dfs(deep);

	cout << distances[deep];
}