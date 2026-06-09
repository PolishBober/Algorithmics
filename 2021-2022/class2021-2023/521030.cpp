#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXK int(1e4) + 1

struct Descroption {
	ll value, count;
	vector <bool> use; 
};

Descroption dp[MAXK];
vector <ll> values;
vector <ll> weights;
ll n, b;
ll answer;

void solv() {
	for(ll i = 0; i < n; ++i)
		dp[0].use.push_back(false);
	for(ll i = 1; i <= b; ++i) {
		for(ll weight = 0; weight < weights.size(); ++weight) {
			if((i == weights[weight] || i > weights[weight] && dp[i - weights[weight]].count && (!dp[i].count || dp[i].value < dp[i - weights[weight]].value + values[weight])) && !dp[i - weights[weight]].use[weight]) {
				dp[i].value = dp[i - weights[weight]].value + values[weight];
				if(dp[answer].value < dp[i].value)
					answer = i;
				dp[i].count = dp[i - weights[weight]].count + 1;
				dp[i].use = dp[i - weights[weight]].use;
				dp[i].use[weight] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		weights.push_back(a);
	}
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		values.push_back(a);
	}

	solv();

	// for(ll i = 0; i <= b; ++i) {
		// cout << i << '-' << dp[i].value << ' ' << dp[i].count << '\n';
	// }

	cout << dp[answer].value << '\n';
	cout << dp[answer].count << '\n';
	for(ll i = 0; i < n; ++i) {
		if(dp[answer].use[i]) {
			cout << i + 1 << ' ';
		}
	}

	return 0;
}