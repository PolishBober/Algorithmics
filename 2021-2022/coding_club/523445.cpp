#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6;
vector <int> graph[maxn + 1];
int weights[maxn + 1];
ll distances[maxn + 1];
ll maximum;
int n;

void dfs(ll vertex, ll father) {
	distances[vertex] = distances[father] + weights[vertex];
	maximum = max(maximum, distances[vertex]);
	for(auto edge : graph[vertex])
		if(distances[edge] < 0)
			dfs(edge, vertex);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(auto & d : distances)
		d = -1;

	cin >> n;
	int a, b;
	for(ll i = 1; i <= n; ++i) {
		cin >> a;
		weights[i] = a;
	
}	for(ll i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	distances[1] = 0;
	dfs(1, 1);
	cout << maximum;
}