#include <bits/stdc++.h>
#define ll long long
using namespace std;

stack <ll> stos;
ll n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(ll i = 0; i < n; ++i) {
		char type;
		cin >> type;
		if(type == '+') {
			ll number;
			cin >> number;
			stos.push(number);
		}
		else {
			cout << stos.top() << '\n';
			stos.pop();
		}
	}
}