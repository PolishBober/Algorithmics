#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6) + 2

vector <ll> graph[2][MAXN];
bool available[2][MAXN];
vector <ll> post;
ll allocation[MAXN];
vector <ll> members[MAXN];
ll n, m;
ll k;

void dfs(ll vertex, bool dimension, ll k_ = 0) {
	if(dimension) {
		members[k_].push_back(vertex);
		allocation[vertex] = k_;
	}
	available[dimension][vertex] = true;
	for(auto edge : graph[dimension][vertex]) {
		if(dimension && edge == vertex && members[k_].back() == vertex)
			members[k_].push_back(vertex);
		if(!available[dimension][edge])
			dfs(edge, dimension, k_);
	}
	if(!dimension)
		post.push_back(vertex);
}

void scc() {
	for(ll i = 1; i <= n + 1; ++i)
		if(!available[0][i])
			dfs(i, 0);
	for(ll i = n; i >= 0; --i)
		if(!available[1][post[i]])
			dfs(post[i], 1, ++k);
}


struct Topo {
	ll index, vlaue;
};

#define INF (ll)36500

multiset <ll> newGraph[MAXN];
ll edges[MAXN];
ll options[MAXN];
queue <ll> todo;
vector <Topo> topological;
bool clean[MAXN];
ll maximum;

void clear(ll vertex) {
	clean[vertex] = true;
	for(auto edge : newGraph[vertex])
		if(!clean[edge])
			clear(edge);
}


void prep() {
	for(ll i = 1; i <= n + 1; ++i) {
		for(auto edge : graph[0][i]) {
			if(allocation[i] != allocation[edge]) {
				newGraph[allocation[i]].insert(allocation[edge]);
				++edges[allocation[edge]];
			}
		}
	}

	clear(allocation[n + 1]);
	for(ll i = 1; i <= k; ++i) {
		if(!clean[i]) {
			for(auto edge : newGraph[i])
				--edges[edge];
			newGraph[i].clear();
		}
	}

	options[allocation[n + 1]] = 1;
	todo.push(allocation[n + 1]);
	for(ll i = 1; i <= k; ++i)
		if(members[i].size() > 1 && clean[i])
			options[i] = INF;
}

void toposort() {
	prep();
	while(!todo.empty()) {
		auto top = todo.front();
		todo.pop();
		if(!edges[top])
			maximum = max(min(INF, maximum), min(INF, options[top]));
		for(auto edge : newGraph[top]) {
			--edges[edge];
			options[edge] = min(options[edge] + options[top], INF);
			if(!edges[edge]) {
				maximum = max(min(INF, maximum), min(INF, options[edge]));
				todo.push(edge);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[0][b].push_back(a);
		graph[1][a].push_back(b);
	}

	scc();
	toposort();
	set <ll> answer;
	for(ll i = 1; i <= k; ++i)
		if(options[i] >= maximum)
			for(auto mem : members[i])
				if(mem != n + 1)
					answer.insert(mem);
	if(answer.size() == 0)
		maximum = 0;

	if(maximum == INF)
		cout << "nieskonczonosc" << '\n';
	else
		cout << maximum << '\n';
	cout << answer.size() << '\n';
	for(auto a : answer)
		cout << a << ' ';

	return 0;
}