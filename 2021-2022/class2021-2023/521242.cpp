#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5) + 1

vector <vector<pair<ll, ll>>> dp;
vector <ll> input;
ll n, m;

ll binsearch1(ll value) {
	ll beg = -1, end = dp.size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(dp[mid].back().first < value)
			beg = mid;
		else
			end = mid;
	}
	return end;
}

ll binsearch2(ll value, ll index) {
	ll beg = -1, end = dp[index].size() - 1;
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(dp[index][mid].first >= value)
			beg = mid;
		else
			end = mid;
	}
	return end;
}

void solv() {
	dp.push_back({{0, 1}});
	for(auto in : input) {
		ll index = binsearch1(in);
		if(index == dp.size())
			dp.push_back({});
		dp[index].push_back({in, 0});
		for(ll i = binsearch2(in, index - 1); i < dp[index - 1].size(); ++i)
			dp[index].back().second = (dp[index].back().second + dp[index - 1][i].second) % m;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		input.push_back(a);
	}

	solv();

	ll answer = 0;
	for(auto d : dp.back())
		answer = (answer + d.second) % m;
	cout << answer;

	return 0;
}