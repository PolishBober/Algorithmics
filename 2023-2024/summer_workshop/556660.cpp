#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(64e4 + 1)

ll input[MAXN];
ll n;

ll modulo(ll value, ll mod) {
	return (value + mod) % mod;
}

pair <ll, ll> simulation(ll index, ll value) {
	ll beg = index, end = index + 1;
	while(value >= input[beg] || value >= input[end]) {
		while(beg != end && value >= input[beg]) {
			value += input[beg];
			beg = modulo(beg - 1, n);
		}
		while(beg != end && value >= input[end]) {
			value += input[end];
			end = modulo(end + 1, n);
		}

		if(beg == end) {
			if(value >= input[beg])
				return {-1, -1};
			break;
		}
	}
	return {beg, end};
}

bool condition(ll value) {
	ll start = 0;
	while(start < n) {
		pair <ll, ll> help = simulation(start, value);
		if(help.first < 0)
			return true;
		if(start + 1 > help.second)
			return false;
		start = help.second;
	}
	return false;
}

void binsearch() {
	ll beg = -1, end = 1e13;
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(condition(mid))
			end = mid;
		else
			beg = mid;
	}
	cout << end << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i)
		cin >> input[i];

	binsearch();

	return 0;
}