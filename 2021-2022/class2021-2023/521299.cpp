#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <vector<pair<ll, ll>>> tab;
vector <ll> input;
ll n;

ll binsearch1(ll value) {
	ll beg = -1, end = tab.size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(tab[mid].back().first < value)
			beg = mid;
		else
			end = mid;
	}
	return end;
}

void solv() {
	tab.push_back({{0, 0}});
	for(ll i = 0; i < n; ++i) {
		ll index = binsearch1(input[i]);
		if(index == tab.size())
			tab.push_back({});
		tab[index].push_back({input[i], i});
	}
}

ll binsearch2(ll value, ll index) {
	ll beg = -1, end = tab[index].size() - 1;
	// cout << tab[index].size() << '\n';
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		// cout << mid << '\n';
		// cout << tab[index][mid].first << '\n' << '\n';
		if(tab[index][mid].first >= value)
			beg = mid;
		else
			end = mid;
	}
	return end;
}

void write() {
	vector <ll> answer;
	for(ll i = tab.size() - 1; i > 0; --i) {
		// for(auto a : answer)
			// cout << a << ' ';
		// cout << '\n';
		ll index;
		if(answer.empty())
			index = binsearch2(INT_MAX, i);
		else
			index = binsearch2(input[answer.back()], i);
		answer.push_back(tab[i][index].second);
	}

	cout << answer.size() << '\n';
	for(ll i = answer.size() - 1; i >= 0; --i)
		cout << answer[i] + 1 << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		input.push_back(a);
	}

	solv();

	// for(auto t : tab) {
	// 	for(auto a : t)
	// 		cout << a.first << ' ';
	// 	cout << '\n';
	// }

	write();

	return 0;
}