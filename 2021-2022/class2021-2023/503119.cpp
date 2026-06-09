#include <bits/stdc++.h>
#define ll long long
using namespace std;

map <ll, ll> tab;
ll n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		++tab[a];
	}
	ll answer = -1;
	for(auto t : tab) {
		if(t.second > n / 2)
			answer = t.first;
	}
	if(answer < 0)
		cout << "NIE";
	else
		cout << answer;
}