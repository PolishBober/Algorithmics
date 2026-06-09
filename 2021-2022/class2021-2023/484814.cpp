#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 5e5;
vector <ll> graph[maxn];
ll pre[maxn], post[maxn];
ll time1, time2;
ll n;

void dfs(ll vertex) {
	pre[vertex] = ++time1;
	for(auto edge : graph[vertex])
		if(!pre[edge])
			dfs(edge);
	post[vertex] = ++time2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i < n; ++i) {
		ll boss;
		cin >> boss;
		graph[boss].push_back(i);
	}

	dfs(0);
	ll a, b;
	cin >> a;
	while(a >= 0) {
		cin >> b;
		if(pre[a] < pre[b] && post[a] > post[b])
			cout << "TAK\n";
		else 
			cout << "NIE\n";
		cin >> a;
	}
}