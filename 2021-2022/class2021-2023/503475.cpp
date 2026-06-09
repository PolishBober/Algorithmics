#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define BASE int(1<<16)
ll tree[2 * BASE][21];
ll n, k;

ll const_k(ll index, ll lenght) {
	lenght -= 1;
	ll answer = LLONG_MIN;
	for(ll i = 0; i <= lenght; ++i)
		answer = max(answer, tree[2 * index][i] + tree[2 * index + 1][lenght - i]);
	return answer + tree[index][1];
}

void solv() {
	for(ll i = n - 2; i >= 0; --i)
		for(ll j = 1 << i; j < 1 << (i + 1); ++j)
			for(ll l = 1; l < min(k + 1, (ll)(1 << (n - i))); ++l)
				tree[j][l] = const_k(j, l);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	k /= 2;
	for(ll i = 0; i < n; ++i) {
		for(ll j = 0; j < (1 << i); ++j) {
			ll a, b;
			cin >> a >> b;
			tree[(1 << i) + j][1] = a + b;
		}
	}

	solv();

	ll maximum = 0;
	for(ll i = 1; i <= k; ++i)
		maximum = max(maximum, tree[1][i]);
	cout << maximum;
}