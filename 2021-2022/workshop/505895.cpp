#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5) + 1
#define MAXD 19

struct Edge {
	ll id, weight;
};

vector <Edge> graph[MAXN];
ll levels[MAXN];
ll jp[MAXN][MAXD];
ll pref[MAXN];
ll n;

void dfs(ll vertex) {
	for(ll i = 1; i < MAXD; ++i)
		jp[vertex][i] = jp[jp[vertex][i - 1]][i - 1];
	for(auto edge : graph[vertex]) {
		if(!levels[edge.id]) {
			pref[edge.id] = pref[vertex] + edge.weight;
			levels[edge.id] = levels[vertex] + 1;
			jp[edge.id][0] = vertex;
			dfs(edge.id);
		}
	}
}

ll lca(ll a, ll b) {
	if(levels[a] < levels[b])
		swap(a, b);

	for(ll i = MAXD - 1; i >= 0; --i)
		if(levels[jp[a][i]] >= levels[b])
			a = jp[a][i];

	if(a == b)
		return a;

	for(ll i = MAXD - 1; i >= 0; --i) {
		if(jp[a][i] != jp[b][i]) {
			a = jp[a][i];
			b = jp[b][i];
		}
	}
	return jp[a][0];
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
		cout << pref[a] + pref[b] - 2 * pref[lca(a, b)] << '\n';
		cin >> a;
	}
	return 0;
}