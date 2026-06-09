#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6) + 1

struct Description {
	ll lider, iq_min, iq_max, weight;
};

Description liders[MAXN];
ll n;

ll Find(ll vertex) {
	if(liders[vertex].lider == vertex)
		return vertex;
	liders[vertex].lider = Find(liders[vertex].lider);
	return liders[vertex].lider;
}

void Union(ll vertex1, ll vertex2) {
	vertex1 = Find(vertex1);
	vertex2 = Find(vertex2);
	liders[vertex1].iq_min = min(liders[vertex1].iq_min, liders[vertex2].iq_min);
	liders[vertex1].iq_max = max(liders[vertex1].iq_max, liders[vertex2].iq_max);
	liders[vertex1].weight += liders[vertex2].weight;
	liders[vertex2].lider = vertex1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i) {
		ll m, iq;
		cin >> m >> iq;
		liders[i] = {i, iq, iq, m};
	}

	string type;
	while(cin >> type) {
		ll a, b;
		if(type == "JOIN") {
			cin >> a >> b;
			if(Find(a) != Find(b))
				Union(a, b);
		}
		else if(type == "IQ_MIN") {
			cin >> a;
			cout << liders[Find(a)].iq_min << '\n';
		}
		else if(type == "IQ_MAX") {
			cin >> a;
			cout << liders[Find(a)].iq_max << '\n';
		}
		else {
			cin >> a;
			cout << liders[Find(a)].weight << '\n';
		}
	}
	return 0;
}