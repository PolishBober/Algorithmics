#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e3) + 1
#define MOD 1100000017

ll dp[MAXN][MAXN];
string word;
ll n;

void solv() {
	for(ll i = 0; i < n; ++i)
		dp[i][i] = 1;
	for(ll size = 1; size <= n; ++size) {
		for(ll j = 0; j + size < n; ++j) {
			dp[j][j + size] = (MOD + dp[j + 1][j + size] + dp[j][j + size - 1] - dp[j + 1][j + size - 1]) % MOD;
			if(word[j] == word[j + size])
				dp[j][j + size] = (dp[j][j + size] + dp[j + 1][j + size - 1] + 1) % MOD;
		}
	}
	cout << dp[0][n - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> word;

	solv();

	return 0;
}