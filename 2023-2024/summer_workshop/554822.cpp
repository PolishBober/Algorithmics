#include <bits/stdc++.h>
#include "prolib.h"
#define ll long long
using namespace std;

#define MAXN int(3e5 + 1)

map <int, int> location[MAXN];
int actual[MAXN];
int n, m, z;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(ll i = 1; i < MAXN; ++i)
		actual[i] = i;

	init(n, m, z);
	for(ll i = 1; i <= n; ++i)
		location[i][0] = i;
	for(ll i = 1; i <= m; ++i) {
		int a, b;
		promocja(i, a, b);
		swap(actual[a], actual[b]);
		location[actual[a]][-i] = a;
		location[actual[b]][-i] = b;
	}

	for(ll i = 0; i < z; ++i) {
		int v, t;
		zapytanie(v, t);
		auto it = location[v].lower_bound(-t);
		odpowiedz((*it).second);
	}

	return 0;
}