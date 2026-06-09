#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(3e5) + 1
#define MAXM 8 + 1
#define MAXB int(1 << 8)

ll tab[MAXN][MAXM];
bool bitmask[MAXB];
ll n, m;

bool condition(ll mid) {
	for(auto &b : bitmask)
		b = false;
	for(ll i = 1; i <= n; ++i) {
		ll index = 0;
		for(ll j = 1; j <= m; ++j)
			index += (tab[i][j] >= mid) << (j - 1);
		bitmask[index] = true;
	}

	for(ll i = 0; i < MAXB; ++i)
		for(ll j = i; j < MAXB; ++j)
			if(bitmask[i] && bitmask[j] && (i | j) == (1 << m) - 1)
				return true;
	return false;
}

void binsearch() {
	ll beg = 0, end = 1e9 + 1;
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(condition(mid))
			beg = mid;
		else
			end = mid;
	}
	cout << beg;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 1; i <= n; ++i)
		for(ll j = 1; j <= m; ++j)
			cin >> tab[i][j];

	binsearch();

	return 0;
}