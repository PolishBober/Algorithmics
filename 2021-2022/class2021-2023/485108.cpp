#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e5;
ll tab[maxn + 1];
ll n, m, q;

ll Find(ll vertex) {
	if(tab[vertex] == vertex)
    	return vertex;
  	tab[vertex] = Find(tab[vertex]);
  	return tab[vertex];
}

void Union(ll vertex1, ll vertex2) {
	tab[Find(vertex1)] = Find(vertex2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(ll i = 0; i < maxn + 1; ++i)
		tab[i] = i;

	cin >> n >> m >> q;
	ll a, b;
	for(ll i = 0; i < m; ++i) {
		cin >> a >> b;
		Union(a, b);
	}

	for(ll i = 0; i < q; ++i) {
		cin >> a >> b;
		if(Find(a) == Find(b))
			cout << 'T' << '\n';
		else
			cout << 'N' << '\n';
	}
}