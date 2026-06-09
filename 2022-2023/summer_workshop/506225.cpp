#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5) + 1
#define MAXD 17

ll levels[MAXN];
ll jp[MAXN][MAXD];
ll pref[MAXN];
map <string, ll> names;
ll n;

void init(string nazwa) {
	names[nazwa] = ++n;
	levels[n] = 1;
}

void nowa_osada(string nowa, string stara, int dlugosc) {
	names[nowa] = ++n;
	ll vertex = names[nowa], father = names[stara];

	jp[vertex][0] = father;
	for(ll i = 1; i < MAXD; ++i)
		jp[vertex][i] = jp[jp[vertex][i - 1]][i - 1];

	levels[vertex] = levels[father] + 1;
	pref[vertex] = pref[father] + dlugosc;
}

ll lca(ll a, ll b) {
	if(levels[a] < levels[b])
		swap(a, b);

	for(ll i = MAXD - 1; i >= 0; --i)
		if(levels[jp[a][i]] >= levels[b])
			a = jp[a][i];

	if(a == b)
		return a;

	for(ll i = MAXD - 1; i >= 0; --i) {
		if(jp[a][i] != jp[b][i]) {
			a = jp[a][i];
			b = jp[b][i];
		}
	}
	return jp[a][0];
}

int odleglosc(string pierwsza, string druga) {
	ll a = names[pierwsza], b = names[druga];
	return pref[a] + pref[b] - 2 * pref[lca(a, b)];
}