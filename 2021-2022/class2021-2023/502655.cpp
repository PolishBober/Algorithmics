#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Coordinates {
	ll y, x;
};

#define MAXN int(1e3) + 1

vector <ll> graph[MAXN];
bool available[MAXN];
Coordinates positions[MAXN];
double maximum;
ll n, p, s;

double pitagoras(Coordinates c1, Coordinates c2) {
	return sqrt(pow(abs(c1.y - c2.y), 2) + pow(abs(c1.x - c2.x), 2));
}

void dfs(ll vertex) {
	available[vertex] = true;
	maximum = max(maximum, pitagoras(positions[p], positions[vertex]));
	for(auto edge : graph[vertex])
		if(!available[edge])
			dfs(edge);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> s;
	--p;
	for(ll i = 0; i < n; ++i) {
		ll x, y;
		cin >> positions[i].x >> positions[i].y;
	}
	for(ll i = 0; i < n; ++i) 
		for(ll j = 0; j < n; ++j)
			if(i != j && pitagoras(positions[i], positions[j]) <= s)
				graph[i].push_back(j);

	dfs(p);

	cout << setprecision(3) << fixed << maximum + s;
	return 0;
}