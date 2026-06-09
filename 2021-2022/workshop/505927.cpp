#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5) + 1
#define MAXD 19

struct Edge {
	ll id, weight;
};

struct Description {
	ll id, maximum;
};

vector <Edge> graph[MAXN];
ll levels[MAXN];
Description jp[MAXN][MAXD];
ll n;

void dfs(ll vertex) {
	for(ll i = 1; i < MAXD; ++i) {
		jp[vertex][i].id = jp[jp[vertex][i - 1].id][i - 1].id;
		jp[vertex][i].maximum = max(jp[vertex][i - 1].maximum, jp[jp[vertex][i - 1].id][i - 1].maximum);
	}
	for(auto edge : graph[vertex]) {
		if(!levels[edge.id]) {
			levels[edge.id] = levels[vertex] + 1;
			jp[edge.id][0] = {vertex, edge.weight};
			dfs(edge.id);
		}
	}
}

ll lca(ll a, ll b) {
	if(a == b)
		return 0;
	ll maximum = INT_MIN;
	if(levels[a] < levels[b])
		swap(a, b);

	for(ll i = MAXD - 1; i >= 0; --i) {
		if(levels[jp[a][i].id] >= levels[b]) {
			maximum = max(maximum, jp[a][i].maximum);
			a = jp[a][i].id;
		}
	}

	if(a == b)
		return maximum;

	for(ll i = MAXD - 1; i >= 0; --i) {
		if(jp[a][i].id != jp[b][i].id) {
			maximum = max(maximum, max(jp[a][i].maximum, jp[b][i].maximum));
			a = jp[a][i].id;
			b = jp[b][i].id;
		}
	}
	return max(maximum, max(jp[a][0].maximum, jp[b][0].maximum));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ll a, b, c;
	for(ll i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	levels[1] = 1;
	dfs(1);

	cin >> a;
	while(a >= 0) {
		cin >> b;
		cout << lca(a, b) << '\n';
		cin >> a;
	}
}