#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e5;
vector <ll> graph[maxn + 1];
ll n, m;
bool available[maxn + 1];
bool answer = true;

void dfs(ll vertex, ll father) {
	available[vertex] = true;
	for(auto edge : graph[vertex]) {
		if(!available[edge])
			dfs(edge, vertex);
		else if(edge != father) {
			answer = false;
		}
	}
}

void condition2() {
	for(ll i = 1; i <= n; ++i)
		if(!available[i])
			answer = false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	ll a, b;
	for(ll i = 0; i < m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(a, 0);
	condition2();
	if(answer)
		cout << "TAK";
	else
		cout << "NIE";
}