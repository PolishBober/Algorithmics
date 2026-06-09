#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5) + 1

struct Lider {
	ll lider;
	map <ll, ll> group;
};

Lider liders[MAXN];
ll n, q;

ll Find(ll vertex) {
	if(liders[vertex].lider == vertex)
		return vertex;
	liders[vertex].lider = Find(liders[vertex].lider);
	return liders[vertex].lider;
}

void Union(ll a, ll b) {
	a = Find(a);
	b = Find(b);
	if(liders[a].group.size() < liders[b].group.size())
		swap(a, b);
	liders[b].lider = a;
	for(auto member : liders[b].group)
		liders[a].group[member.first] += liders[b].group[member.first];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(ll i = 1; i <= n; ++i) {
		ll s;
		cin >> s;
		liders[i].lider = i;
		liders[i].group[s] = 1;
	}

	for(ll i = 0; i < q; ++i) {
		char type;
		ll a, b;
		cin >> type >> a >> b;
		if(type == 'D')
			Union(a, b);
		else
			cout << liders[Find(a)].group[b] << '\n';
	}

	return 0;
}