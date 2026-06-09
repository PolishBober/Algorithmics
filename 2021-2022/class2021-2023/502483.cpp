#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(2e6) + 1
vector <ll> graph[MAXN];
ll edges[MAXN];
queue <ll> todo;
vector <ll> input;
ll answer;
ll n, k, r;

void toposort() {
	while(!todo.empty()) {
		auto top = todo.front();
		todo.pop();
		if(top <= n)
			++answer;
		for(auto edge : graph[top]) {
			--edges[edge];
			if(!edges[edge])
				todo.push(edge);
		}
	}
	cout << answer - k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> r;
	ll a;
	for(ll i = 0; i < k; ++i) {
		cin >> a;
		todo.push(a);
		input.push_back(a);
	}
	for(ll i = 0; i < r; ++i) {
		ll s;
		cin >> s;
		for(ll j = 0; j < s; ++j) {
			cin >> a;
			graph[a].push_back(n + i + 1);
			++edges[n + i + 1];
		}
		ll p;
		cin >> p;
		for(ll j = 0; j < p; ++j) {
			ll b;
			cin >> b;
			graph[n + i + 1].push_back(b);
			edges[b] = 1;
		}
	}
	for(auto i : input)
		edges[i] = 0;

	toposort();

	return 0;
}