#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e2) + 1
#define MAXK int(2e4) + 1

struct Description {
	ll value, index;
	vector <ll> use;
};

Description dp[MAXK];
vector <ll> coins;
vector <ll> available;
ll n, k;

void solv() {
	for(ll i = 0; i < n; ++i)
		dp[0].use.push_back(0);
	for(ll i = 1; i <= k; ++i) {
		for(ll coin = 0; coin < coins.size(); ++coin) {
			if((i == coins[coin] || i > coins[coin] && dp[i - coins[coin]].value && (!dp[i].value || dp[i].value > dp[i - coins[coin]].value + 1)) && available[coin] - dp[i - coins[coin]].use[coin] > 0) {
				dp[i].value = dp[i - coins[coin]].value + 1;
				dp[i].index = i - coins[coin];
				dp[i].use = dp[i - coins[coin]].use;
				++dp[i].use[coin];
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		coins.push_back(a);
	}
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		available.push_back(a);
	}

	cin >> k;
	solv();

	cout << dp[k].value << '\n';
	for(ll i = 0; i < n; ++i) {
		cout << dp[k].use[i] << ' ';
	}

	return 0;
}