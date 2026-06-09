#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6 + 1)

ll input[MAXN];
ll n, A, B;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> A >> B;
	for(ll i = 0; i < n; ++i) {
		cin >> input[i];
		input[i] %= (A + B);
	}

	sort(input, input + n);

	ll marek = 0;
	ll bob = 0;
	bool turn = true;
	for(ll i = n - 1; i >= 0; --i) {
		if(turn)
			marek += input[i] / A;
		else
			bob += input[i] / B;
		turn = !turn;
	}
	if(marek > bob)
		cout << "Marek\n";
	else
		cout << "Bob\n";

	return 0;
}