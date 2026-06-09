#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXK int(1e4) + 1

struct Description {
	ll value, index;
};

vector <ll> coins;
Description dp[MAXK];
ll n, q;

void solv() {
	for(ll i = 1; i < MAXK; ++i)
		for(auto coin : coins)
			if(coin == i || i > coin && dp[i - coin].value && (!dp[i].value || dp[i].value > dp[i - coin].value + 1))
				dp[i] = {dp[i - coin].value + 1, i - coin};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		coins.push_back(a);
	}

	solv();

	cin >> q;
	for(ll i = 0; i < q; ++i) {
		ll x;
		cin >> x;
		if(!x)
			cout << 0 << '\n';
		else if(!dp[x].value)
			cout << -1 << '\n';
		else {
			cout << dp[x].value << ' ';
			while(x) {
				cout << x - dp[x].index << ' ';
				x = dp[x].index;
			}
			cout << '\n';
		}
	}

	return 0;
}