#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6) + 1
#define MAXD 20

vector <ll> graph[MAXN];
ll levels[MAXN];
ll jp[MAXN][MAXD];
ll n, m, k;

void dfs(ll vertex) {
	for(ll i = 1; i < MAXD; ++i)
		jp[vertex][i] = jp[jp[vertex][i - 1]][i - 1];
	for(auto edge : graph[vertex]) {
		if(!levels[edge]) {
			jp[edge][0] = vertex;
			levels[edge] = levels[vertex] + 1;
			dfs(edge);
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

	cin >> n >> m >> k;
	for(ll i = 0; i < n - 1; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	levels[1] = 1;
	dfs(1);

	for(ll i = 0; i < k; ++i) {
		ll c, t;
		cin >> c >> t;
		ll help = lca(m, c);
		// cout << help << '\n';
		if(levels[m] - levels[help] <= t) {
			t = min((levels[c] - levels[help]) - (t - levels[m] + levels[help]), levels[c] - levels[help]);
			m = c;
		}
		// cout << m << ' ' << t << '\n';
		for(ll j = MAXD - 1; j >= 0; --j) {
			if(1 << j <= t) {
				m = jp[m][j];
				t -= 1 << j;
			}
		}
		cout << m << ' ';
	}
	return 0;
}