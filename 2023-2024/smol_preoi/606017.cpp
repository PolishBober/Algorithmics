#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6) + 1

vector <ll> graph[2][MAXN];
bool available[2][MAXN];
vector <ll> post;
ll k;
ll allocation[MAXN];
ll n, m;

void dfs(ll vertex, bool dimension, ll k = 0) {
	if(dimension)
		allocation[vertex] = k;
	available[dimension][vertex] = true;
	for(auto edge : graph[dimension][vertex])
		if(!available[dimension][edge])
			dfs(edge, dimension, k);
	if(!dimension)
		post.push_back(vertex);
}

void scc() {
	for(ll i = 1; i <= n; ++i)
		if(!available[0][i])
			dfs(i, 0);
	for(ll i = n - 1; i >= 0; --i)
		if(!available[1][post[i]])
			dfs(post[i], 1, ++k);
}

vector <ll> newGraph[MAXN];
ll edges[MAXN];
ll weights[MAXN];
ll answers[MAXN];
queue <ll> todo;

void prepare() {
	for(ll i = 1; i <= n; ++i) {
		for(auto edge : graph[1][i]) {
			if(allocation[i] != allocation[edge]) {
				newGraph[allocation[i]].push_back(allocation[edge]);
				++edges[allocation[edge]];
			}
			else
				++weights[allocation[i]];
		}
	}
}

void toposort() {
	for(ll i = 1; i <= k; ++i) {
		answers[i] = weights[i];
		if(!edges[i]) {
			todo.push(i);
		}
	}
	while(!todo.empty()) {
		auto top = todo.front();
		todo.pop();
		for(auto edge : newGraph[top]) {
			--edges[edge];
			answers[edge] = max(answers[edge], weights[edge] + answers[top] + 1);
			if(!edges[edge])
				todo.push(edge);
		}
	}
	for(ll i = 1; i <= n; ++i)
		cout << answers[allocation[i]] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[0][a].push_back(b);
		graph[1][b].push_back(a);
	}

	scc();

	prepare();

	toposort();

	return 0;
}