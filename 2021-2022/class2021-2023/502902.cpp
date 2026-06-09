#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
	ll lider, value;
};

vector <Description> stos;
ll n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	stos.push_back({0, -1});
	for(ll i = 0; i < n; ++i) {
		char type;
		cin >> type;
		if(type == '+') {
			ll x;
			cin >> x;
			stos.push_back({stos.size() - 1, x});
		}
		else if(type == '-') {
			stos.push_back({stos[stos.back().lider].lider, stos[stos.back().lider].value});
		}
		else {
			ll y;
			cin >> y;
			stos.push_back({stos[stos.size() - y - 1].lider, stos[stos.size() - y - 1].value});
		}

		cout << stos.back().value << '\n';
	}
	return 0;
}