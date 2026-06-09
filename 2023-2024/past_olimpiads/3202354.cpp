#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e5 + 7)
#define MAXLOG 16

bitset <MAXN> chain;

ll n, m;

// ile jest
ll numbers[2 * MAXN];
// ile jest
ll lenghts[MAXLOG + 7];


set <ll> answer;
void prep() {

	answer.insert(MAXLOG + 1);
	for(ll lenght = 1; lenght <= MAXLOG; ++lenght) {
		answer.insert(lenght);

		ll cut = 0;
		for(ll i = 0; i < lenght; ++i)
			cut += chain[i] << i;

		for(ll i = 0; i <= n - lenght; ++i) {

			ll number = cut + (1 << lenght);

			if(!numbers[number]) {
				ll log = log2(number);
				++lenghts[log];
				if(lenghts[log] == (1 << log))
					answer.erase(log);
			}
			++numbers[number];

			cut += chain[i + lenght] << lenght;
			cut /= 2;
		}
	}
}


ll last = INT_MAX;
void change(ll index) {


	for(ll lenght = 1; lenght <= MAXLOG; ++lenght) {

		ll cut = 0;
		for(ll i = 0; i < lenght; ++i)
			cut += chain[max((ll) 0, index - lenght + 1) + i] << i;

		for(ll i = max((ll) 0, index - lenght + 1); i + lenght <= min(index + lenght, n); ++i) {
			
			ll number = cut + (1 << lenght);
			
			--numbers[number];
			if(!numbers[number]) {
				ll log = log2(number);
				if(lenghts[log] == (1 << log))
					answer.insert(log);
				--lenghts[log];
			}


			if(chain[index])
				cut ^= 1 << (index - i);
			else
				cut |= 1 << (index - i);
			number = cut + (1 << lenght);


			if(!numbers[number]) {
				ll log = log2(number);
				++lenghts[log];
				if(lenghts[log] == (1 << log))
					answer.erase(log);
			}
			++numbers[number];


			if(!chain[index])
				cut ^= 1 << (index - i);
			else
				cut |= 1 << (index - i);
			number = cut + (1 << lenght);

			cut += chain[i + lenght] << lenght;
			cut /= 2;
		}
	}
	chain[index] = !chain[index];


	cout << *answer.begin() << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> chain;

	chain[0] = !chain[0];
	prep();

	change(0);

	for(ll i = 0; i < m; ++i) {
		ll a;
		cin >> a;
		change(n - a);
	}

	return 0;
}