#include <bits/stdc++.h>
using namespace std;

#define MAXN int(1e6) + 1
#define MAXD 20

vector <int> graph[MAXN];
int levels[MAXN];
int jp[MAXN][MAXD];
int n, m, k;

void dfs(int vertex) {
	for(int i = 1; i < MAXD; ++i)
		jp[vertex][i] = jp[jp[vertex][i - 1]][i - 1];
	for(auto edge : graph[vertex]) {
		if(!levels[edge]) {
			jp[edge][0] = vertex;
			levels[edge] = levels[vertex] + 1;
			dfs(edge);
		}
	}
}

int lca(int a, int b) {
	if(levels[a] < levels[b])
		swap(a, b);

	for(int i = MAXD - 1; i >= 0; --i)
		if(levels[jp[a][i]] >= levels[b])
			a = jp[a][i];

	if(a == b)
		return a;

	for(int i = MAXD - 1; i >= 0; --i) {
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
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	levels[1] = 1;
	dfs(1);

	for(int i = 0; i < k; ++i) {
		int c, t;
		cin >> c >> t;
		int help = lca(m, c);
		if(levels[m] - levels[help] <= t) {
			t = min((levels[c] - levels[help]) - (t - levels[m] + levels[help]), levels[c] - levels[help]);
			m = c;
		}
		for(int j = MAXD - 1; j >= 0; --j) {
			if(1 << j <= t) {
				m = jp[m][j];
				t -= 1 << j;
			}
		}
		cout << m << ' ';
	}
	return 0;
}