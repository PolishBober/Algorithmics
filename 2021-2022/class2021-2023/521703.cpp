#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> input1;
vector <ll> input2;
vector <vector<pair<ll, ll>>> dp1;
vector <vector<pair<ll, ll>>> dp2;
ll n, m;

ll binsearch1(ll value, vector<vector<pair<ll, ll>>> &dp) {
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

void first() {
	dp1.push_back({{0, 0}});
	for(ll i = 0; i < n; ++i) {
		ll index = binsearch1(input1[i], dp1);
		if(index == dp1.size())
			dp1.push_back({});
		dp1[index].push_back({input1[i], i});
	}
}


ll iterate1(ll value, ll index) {
	ll answer = INT_MAX;
	for(ll i = dp2[index].size() - 1; i >= 0 && dp2[index][i].first < value; --i)
		answer = min(answer, dp2[index][i].second);
	return answer;
}

ll binsearch2(ll value) {
	ll beg = -1, end = dp1.size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(dp1[mid][0].first >= value)
			end = mid;
		else
			beg = mid;
	}
	return end;
}

ll binsearch3(ll value, ll index, ll last) {
	ll beg = -1, end = dp1[index].size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(dp1[index][mid].first > value || dp1[index][mid].first == value && dp1[index][mid].second <= last)
			beg = mid;
		else
			end = mid;
	}
	if(end == dp1[index].size())
		return -1;
	if(dp1[index][end].first == value)
		return dp1[index][end].second;
	return -1;
}

ll iterate2(ll value, ll beg, ll last) {
	ll answer = -1;
	for(ll j = beg; j < dp1.size() && dp1[j].back().first <= value; ++j) {
		answer = binsearch3(value, j, last);
		if(answer >= 0)
			break;
	}
	return answer;
}

void second() {
	dp2.push_back({{0, -1}});
	for(auto in : input2) {
		ll index = binsearch1(in, dp2);
		ll last = iterate1(in, index - 1);

		ll find = binsearch2(in);
		if(find == dp1.size())
			continue;
		ll match = iterate2(in, find, last);
		if(match < 0)
			continue;

		if(index == dp2.size())
			dp2.push_back({});
		dp2[index].push_back({in, match});
	}
}

ll binsearch4(ll value, ll index, ll last) {
	ll beg = -1, end = dp2[index].size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(dp2[index][mid].first >= value)
			beg = mid;
		else
			end = mid;
	}
	for(end; end < dp2[index].size() && dp2[index][end].second >= last; ++end) {}
	return dp2[index][end].second;
}

void write() {
	vector <ll> answer;
	for(ll i = dp2.size() - 1; i > 0; --i) {
		ll index;
		if(answer.empty())
			index = dp2[i][0].second;
		else
			index = binsearch4(input1[answer.back()], i, answer.back());
		answer.push_back(index);
	}

	cout << answer.size() << '\n';
	for(ll i = answer.size() - 1; i >= 0; --i)
		cout << input1[answer[i]] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		input1.push_back(a);
	}

	first();

	// for(auto d : dp1) {
	// 	for(auto p : d)
	// 		cout << p.first << ' ';
	// 	cout << '\n';
	// }
	// cout << '\n';

	for(ll i = 0; i < m; ++i) {
		ll a;
		cin >> a;
		input2.push_back(a);
	}

	second();

	// cout << '\n';
	// for(auto d : dp2) {
	// 	for(auto p : d)
	// 		cout << p.first << ' ';
	// 	cout << '\n';
	// }
	// cout << '\n';
	// for(auto d : dp2) {
	// 	for(auto p : d)
	// 		cout << p.second << ' ';
	// 	cout << '\n';
	// }

	write();

	return 0;
}