#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5 + 7)
#define MAXK int(1 << 8)

ll graph[MAXN];
ll weights[MAXN];
ll n, m, k;

ll dp[MAXN][MAXK];
void solv() {

	for(ll j = 1; j < MAXK; j += 2)
		dp[n][j] = weights[n];

	for(ll i = n - 1; i > 0; --i) {
		for(ll j = 0; j < MAXK; ++j) {
			// actual vertex in
			if(j % 2)
				dp[i][j] = dp[i + 1][((j >> 1) | graph[i]) % MAXK] + weights[i];
			// without actual vertex
			else
				dp[i][j] = dp[i + 1][(j >> 1) % MAXK];
		}
	}

	for(ll i = 1; i <= n; ++i)
		cout << dp[i][(graph[i] << 1) % MAXK + 1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(ll i = 1; i <= n; ++i)
		cin >> weights[i];
	for(ll i = 0; i < m; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a] |= (1 << (b - a - 1));
	}

	solv();

	return 0;
}