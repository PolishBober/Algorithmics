#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e5;
char tab[maxn];
ll n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(ll i = 0; i < n; ++i)
		cin >> tab[i];

	ll answer = 0;
	ll beg = 0, action = (tab[0] == 'a');
	for(ll end = 0; end < n; ++end) {
		while(beg + 1 < n && action + (tab[beg + 1] == 'a') <= k)
			action += (tab[++beg] == 'a');
		answer = max(answer, beg - end + 1);
		action -= (tab[end] == 'a');
	}

	beg = 0;
	action = (tab[0] == 'b');
	for(ll end = 0; end < n; ++end) {
		while(beg + 1 < n && action + (tab[beg + 1] == 'b') <= k)
			action += (tab[++beg] == 'b');
		answer = max(answer, beg - end + 1);
		action -= (tab[end] == 'b');
	}

	cout << answer;
}