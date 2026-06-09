#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> dp;
ll n;

ll binsearch(ll wanted) {
	ll beg = 0, end = dp.size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(dp[mid] < wanted)
			beg = mid;
		else
			end = mid;
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	dp.push_back(0);
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		if(a <= dp.back())
			dp[binsearch(a)] = a;
		else
			dp.push_back(a);
	}
	cout << dp.size() - 1;
}