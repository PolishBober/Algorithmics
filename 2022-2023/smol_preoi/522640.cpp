#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(4e6) + 1
#define MOD (int(1e9) + 7)

ll power(ll base, ll exponent) {
	base %= MOD;
	ll answer = 1;
	while(exponent > 1) {
		if(exponent % 2)
			answer = (answer * base) % MOD;
		base = (base * base) % MOD;
		exponent /= 2;
	}
	return (answer * base) % MOD;
}

ll powers[MAXN];
ll strong[MAXN];
ll _strong[MAXN];
ll denominator[MAXN];
ll n;

void preproc() {
	powers[1] = 2;
	for(ll i = 2; i <= n; ++i)
		powers[i] = (powers[i - 1] * 2) % MOD;

	strong[0] = 1;
	for(ll i = 1; i <= n; ++i)
		strong[i] = (strong[i - 1] * i) % MOD;

	_strong[n] = power(strong[n], int(1e9) + 5);
	for(ll i = n - 1; i >= 0; --i)
		_strong[i] = (_strong[i + 1] * (i + 1)) % MOD;
}

void solv() {
	if(n % 2) {
		cout << power(3, n);
		return;
	}

	ll answer = 0; 
	for(ll i = 0; i < n / 2; ++i)
		answer = (answer + ((powers[n - i] * strong[n] % MOD) * (_strong[i] * _strong[n - i] % MOD) % MOD)) % MOD;
	cout << answer;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	preproc();

	solv();

	return 0;
}