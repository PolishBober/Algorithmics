#include <bits/stdc++.h>
#define ll long long
using namespace std;

int nwd(int a, int b) {
	do {
		if(a > b)
			swap(a, b);
		b %= a;
	} while(b);
	return a;
}

#define MAXN int(1e6 + 1)

int input[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i)
		cin >> input[i];
	
	ll answer = 0;
	for(ll i = 0; i < n; ++i)
		for(ll j = i + 1; j < n; ++j)
			answer += nwd(input[i], input[j]);

	cout << answer << '\n';

	return 0;
}