#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e3)

ll input1[MAXN];
ll input2[MAXN];
ll dp[MAXN];
ll n;

ll iterate(ll beg, ll end) {
	ll answer = 0;
	for(beg; beg <= end; ++beg)
		answer = max(answer, dp[beg]);
	return answer;
}

void solv() {
	ll answer = 0;
	for(ll i = 1; i <= n; ++i) {
		ll maximum = 0;
		for(ll j = 0; j <= n; ++j) {
			if(input2[j] == input1[i]) {
				ll help = dp[j];
				dp[j] = maximum + input1[i];
				maximum = max(maximum, help);
			}
			else
				maximum = max(maximum, dp[j]);
			answer = max(answer, dp[j]);
		}
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i)
		cin >> input1[i];
	for(ll i = 1; i <= n; ++i)
		cin >> input2[i];

	solv();

	return 0;
}