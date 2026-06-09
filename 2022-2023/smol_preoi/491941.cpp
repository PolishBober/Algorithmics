#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 2e5;
ll tab[maxn + 1];
ll n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(ll i = 0; i < n; ++i)
		cin >> tab[i];

	sort(tab, tab + n);
	ll sum = 0;
	const ll start = ceil(double(n + 1) / 2) - 1;
	ll index = start;
	while(sum + (tab[++index] - tab[index - 1]) * (index - start) <= k && index < n) {
		sum += (tab[index] - tab[index - 1]) * (index - start);
	}
	cout << tab[index - 1] + (k - sum) / (index - start) - tab[start];
}