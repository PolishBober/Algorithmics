#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e6) + 1

struct Description {
	ll value;
	bool taken; 
};

Description dp[MAXN];
ll input[MAXN];
ll n;

void solv() {
	dp[1] = {9, true};
	for(ll i = 2; i <= n; ++i) {
		if(dp[i - 2].value + input[i - 1] + 9 < dp[i - 1].value + 9 * !dp[i - 1].taken + input[i] * dp[i - 1].taken)
			dp[i] = {dp[i - 1].value + 9 * !dp[i - 1].taken + input[i] * dp[i - 1].taken, !dp[i - 1].taken};
		else
			dp[i] = {dp[i - 2].value + input[i - 1] + 9, true};
	}
	cout << dp[n].value;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i)
		cin >> input[i];

	solv();

	return 0;
}