#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5) + 1

vector <ll> tab;
vector <ll> dp;
ll n;

ll binsearch(ll value) {
	ll beg = -1, end = dp.size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(dp[mid] < value)
			beg = mid;
		else
			end = mid;
	}
	return end;
}

void solv() {
	for(auto t : tab) {
		ll index = binsearch(t);
		if(index == dp.size())
			dp.push_back(t);
		else
			dp[index] = t;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		tab.push_back(a);
	}

	solv();

	cout << dp.size();

	return 0;
}