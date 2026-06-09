#include <bits/stdc++.h>
#define ll long long
using namespace std;

set <ll> blocks;
ll n;

ll clear(ll w) {
	ll answer = 0, last = -1;
	auto help = blocks.upper_bound(w);
	while(help != blocks.end()) {
		if(*help != last)
			++answer;
		last = *help;
		blocks.erase(help);
		help = blocks.upper_bound(w);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	ll last = 0;
	ll answer = 0;
	for(ll i = 0; i < n; ++i) {
		ll d, w;
		cin >> d >> w;
		blocks.insert(w);
		answer += clear(w);
	}
	answer += clear(0);
	cout << answer;
	return 0;
}