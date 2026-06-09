#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e3) + 1

struct Description {
	ll lider, count;
};

Description liders[MAXN];
ll n, q;

ll Find(ll vertex) {
	if(liders[vertex].lider == vertex)
		return vertex;
	liders[vertex].lider = Find(liders[vertex].lider);
	return liders[vertex].lider;
}

void Union(ll vertex1, ll vertex2) {
	vertex1 = Find(vertex1);
	vertex2 = Find(vertex2);
	liders[vertex1].count += liders[vertex2].count;
	liders[vertex2].lider = vertex1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(ll i = 0; i < MAXN; ++i)
		liders[i] = {i, 1};

	cin >> n >> q;
	for(ll i = 0; i < q; ++i) {
		ll a, b;
		cin >> a >> b;
		if(Find(a) != Find(b))
			Union(a, b);
		cout << liders[Find(1)].count << '\n';
	}
	return 0;
}