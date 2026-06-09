#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(2e5 + 1)


ll dp[MAXN][3];
ll n;

void solv() {
	for(ll i = 1; i < n; ++i) {
		dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += max(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i)
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

	solv();


	return 0;
}