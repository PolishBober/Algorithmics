#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5 + 7)

vector <ll> graph[MAXN];

ll n, m;

ll done[MAXN];
ll numbers[MAXN];
ll number;
bool check = true;
void dfs(ll vertex) {
	if(2 * done[vertex] < graph[vertex].size() && vertex != 1 && vertex != 2)
		return;

	if(vertex == 2 && done[vertex] < graph[vertex].size())
		return;

	numbers[vertex] = ++number;

	for(auto edge : graph[vertex]) {
		if(numbers[edge] == 0) {
			++done[edge];
			dfs(edge);
		}
		else if(numbers[vertex] < numbers[edge])
			check = false;
	}

}


void solv() {
	dfs(1);

	for(ll i = 2; i <= n; ++i)
		if(graph[i].empty())
			numbers[i] = ++number;

	ll help = 0;
	for(ll i = 1; i <= n; ++i)
		if(numbers[i])
			++help;

	if(help != n || !check) {
		cout << "NIE\n";
		return;
	}

	cout << "TAK\n";
	for(ll i = 1; i <= n; ++i)
		cout << numbers[i] << ' ';
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	solv();

	return 0;
}