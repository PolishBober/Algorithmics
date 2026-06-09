#include <bits/stdc++.h>
using namespace std;

#define MAXN int(1e5 + 3)

vector <pair<int,int>> input;
int n, m;

int fathers[MAXN];

int Find(int a) {
	if(a == fathers[a])
		return a;
	fathers[a] = Find(fathers[a]);
	return fathers[a];
}

void Union(int a, int b) {
	fathers[Find(b)] = fathers[Find(a)];
}


vector <int> graph[MAXN];
int values[MAXN];
bool answer;

void dfs(int vertex, int value = 1) {
	if(!answer)
		return;
	values[vertex] = value;
	for(auto edge : graph[vertex]) {
		if(values[edge] && values[edge] == value) {
			answer = false;
			return;
		}
		if(!values[edge])
			dfs(edge, !(value - 1) + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for(int turn = 0; turn < t; ++turn) {
		answer = true;
		cin >> n >> m;
		for(int i = 0; i <= n; ++i)
			fathers[i] = i;
		for(int i = 0; i < m; ++i) {
			int x, y;
			char c;
			cin >> x >> y >> c;
			if(c == 'A')
				Union(x, y);
			else
				input.push_back({x, y});
		}
		
		for(auto in : input) {
			graph[Find(in.first)].push_back(Find(in.second));
			graph[Find(in.second)].push_back(Find(in.first));
		}

		// for(int i = 0; i <= n; ++i) {
		// 	cout << i << ':';
		// 	for(auto edge : graph[i])
		// 		cout << edge << ' ';
		// 	cout << '\n';
		// }

		for(auto in : input) {
			if(!values[Find(in.first)]) {
				dfs(Find(in.first));
				if(!answer)
					break;
			}
		}
		
		if(answer)
			cout << "TAK\n";
		else
			cout << "NIE\n";

		input.clear();
		for(int i = 0; i <= n; ++i) {
			values[i] = 0;
			graph[i].clear();
		}
	}



	return 0;
}