#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 2e4;
ll tab[maxn];
ll n, k;

bool condition(ll mid) {
	for(ll glass = 0; glass < 2; ++glass) {
		ll sum = 0;
		for(ll i = 1; i < n; ++i) {
			if(tab[i - 1] < tab[i])
				sum += tab[i] - tab[i - 1];
			if(i + 1 >= mid && sum <= k)
				return true;
			if(i + 1 >= mid && tab[i - mid + 1] < tab[i - mid + 2])
				sum -= tab[i - mid + 2] - tab[i - mid + 1];
		}
		reverse(tab, tab + n);
	}
	return false;
}

void binsearch() {
	ll beg = 0, end = maxn + 1;
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(condition(mid))
			beg = mid;
		else
			end = mid;
	}
	cout << beg;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(ll i = 0; i < n; ++i)
		cin >> tab[i];

	binsearch();
}