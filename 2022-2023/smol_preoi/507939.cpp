#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5) + 1
#define MAXP 17

vector <ll> graph[MAXN];
ll jp[MAXN][MAXP];
ll levels[MAXN];
ll pre[MAXN];
ll _pre[MAXN];
ll order;
set <ll> tribe[MAXN];
ll lider[MAXN];
ll n, k, q;

void dfs(ll vertex) {
	pre[vertex] = ++order;
	_pre[order] = vertex;
	for(ll i = 1; i < MAXP; ++i)
		jp[vertex][i] = jp[jp[vertex][i - 1]][i - 1];
	for(auto edge : graph[vertex]) {
		if(!levels[edge]) {
			levels[edge] = levels[vertex] + 1;
			jp[edge][0] = vertex;
			dfs(edge);
		}
	}
}

ll lca(ll a, ll b) {
	if(levels[a] < levels[b])
		swap(a, b);

	for(ll i = MAXP - 1; i >= 0; --i)
		if(levels[jp[a][i]] >= levels[b])
			a = jp[a][i];

	if(a == b)
		return a;

	for(ll i = MAXP - 1; i >= 0; --i) {
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

	cin >> n >> k;
	for(ll i = 0; i < n - 1; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	levels[1] = 1;
	dfs(1);

	for(ll i = 1; i <= n; ++i) {
		ll a;
		cin >> a;
		lider[i] = a;
		tribe[a].insert(pre[i]);
		tribe[a].insert(-pre[i]);
	}

	cin >> q;
	for(ll i = 0; i < q; ++i) {
		char type;
		cin >> type;
		if(type == 'U') {
			ll x, y;
			cin >> x >> y;
			tribe[lider[x]].erase(pre[x]);
			tribe[lider[x]].erase(-pre[x]);
			lider[x] = y;
			tribe[y].insert(pre[x]);
			tribe[y].insert(-pre[x]);
		}
		else {
			ll x;
			cin >> x;
			if(tribe[x].empty())
				cout << -1 << '\n';
			else
				cout << lca(_pre[*tribe[x].lower_bound(0)], _pre[-*tribe[x].lower_bound(INT_MIN)]) << '\n';
		}
	}
	return 0;
}