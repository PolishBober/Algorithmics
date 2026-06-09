#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define BASE int(1 << 17)

ll tree[2 * BASE];

void set_interval(ll beg, ll end, ll value) {
	beg += BASE;
	end += BASE;
	while(beg <= end) {
		if(beg % 2)
			tree[beg] += value;
		if(!(end % 2))
			tree[end] += value;
		beg = (beg + 1) / 2;
		end = (end - 1) / 2;
	}
}

ll query_point(ll vertex) {
	vertex += BASE;
	ll answer = 0;
	while(vertex) {
		answer += tree[vertex];
		vertex /= 2;
	}
	return answer;
}

#define MAXN int(1e5) + 1
#define MAXP 17

struct Edge {
	ll id, weight;
};

struct Input {
	ll a, b, c;
};


vector <Edge> graph[MAXN];
ll jp[MAXN][MAXP];
ll levels[MAXN];
ll pre[MAXN];
ll order;
ll subtree[MAXN];

Input input[MAXN];
ll weights[MAXN];
ll n, m;

void dfs(ll vertex) {
	pre[vertex] = ++order;
	for(ll i = 1; i < MAXP; ++i)
		jp[vertex][i] = jp[jp[vertex][i - 1]][i - 1];
	for(auto edge : graph[vertex]) {
		if(!levels[edge.id]) {
			jp[edge.id][0] = vertex;
			levels[edge.id] = levels[vertex] + 1;
			weights[edge.id] = edge.weight;
			dfs(edge.id);
		}
	}
	subtree[jp[vertex][0]] += subtree[vertex] + 1;
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

	cin >> n >> m;
	for(ll i = 1; i <= n - 1; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		input[i] = {a, b, c};
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	levels[1] = 1;
	dfs(1);

	for(ll i = 1; i <= n; ++i)
		set_interval(pre[i], pre[i] + subtree[i], weights[i]);

	for(ll i = 0; i < m; ++i) {
		char type;
		ll x, y;
		cin >> type >> x >> y;
		if(type == 'O')
			cout << query_point(pre[x]) + query_point(pre[y]) - 2 * query_point(pre[lca(x, y)]) << '\n';
		else {
			ll v;
			if(jp[input[x].a][0] == input[x].b)
				v = input[x].a;
			else
				v = input[x].b;
			set_interval(pre[v], pre[v] + subtree[v], y - weights[v]);
			weights[v] = y;
		}
	}

	return 0;
}