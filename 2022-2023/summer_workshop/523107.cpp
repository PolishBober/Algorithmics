#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define BASE 257
#define MOD1 (int(1e9) + 7)
#define MOD2 (int(1e9) + 9)

#define MAXN int(1e6) + 1

pair <ll, ll> powers[MAXN];
bool check[MAXN];
pair <ll, ll> hashe[MAXN];
ll n;
char word[MAXN];

void preproc() {
	powers[0] = {1, 1};
	for(ll i = 1; i <= n; ++i) {
		powers[i].first = powers[i - 1].first * BASE % MOD1;
		powers[i].second = powers[i - 1].second * BASE % MOD2;
	}

	ll index = 0;
	for(ll i = 0; index >= 0; ++i) {
		bitset <20> help;
		help = i;
		ll last = 0;
		for(ll i = 0; i < 20; ++i)
			if(help[i])
				last = i;
		for(last; last >= 0; --last) {
			if(index > n) {
				index = -1;
				break;
			}
			check[index++] = help[last];
		}
	}
}

void hashing() {
	for(ll i = 1; i <= n; ++i) {
		hashe[i].first = (hashe[i - 1].first * BASE + word[i]) % MOD1;
		hashe[i].second = (hashe[i - 1].second * BASE + word[i]) % MOD2;
	}
}

pair <ll, ll> subword(ll a, ll b) {
	return {(MOD1 + hashe[b].first - hashe[a].first * powers[b-a].first % MOD1) % MOD1, (MOD2 + hashe[b].second - hashe[a].second * powers[b-a].second % MOD2) % MOD2};
}

bool condition(ll size) {
	pair <ll, ll> pif = subword(0, size);
	pair <ll, ll> paf;
	ll pafIndex = -1;
	ll i;
	for(i = size; i + size <= n; i += size) {
		auto help = subword(i, i + size);
		if(check[i / size]) {
			if(pafIndex == -1) {
				paf = help;
				pafIndex = i;
			}
			if(help != paf)
				return false;
		}
		else if(help != pif)
			return false;
	}
	if(i < n) {
		if(check[i / size]) {
			if(pafIndex == -1)
				return true;
			if(subword(pafIndex, pafIndex + n - i) != subword(i, n))
				return false;
		}
		else if(subword(0, n - i) != subword(i, n))
			return false;
	}
	return true;
}

void solv() {
	for(ll size = 1; size <= n; ++size) {
		if(condition(size)) {
			if(n % size)
				cout << n / size + 1;
			else
				cout << n / size;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i)
		cin >> word[i];

	preproc();

	hashing();

	solv();

	return 0;
}