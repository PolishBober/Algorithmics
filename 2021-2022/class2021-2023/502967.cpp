#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
	ll lider;
	char value;
};

vector <Description> stos;
ll n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	stos.push_back({0, '.'});
	for(ll i = 0; i < n; ++i) {
		string type;
		cin >> type;
		if(type == "dopisz") {
			char letter;
			cin >> letter;
			stos.push_back({stos.size() - 1, letter});
		}
		else if(type == "backspace")
			stos.push_back({stos[stos.back().lider].lider, stos[stos.back().lider].value});
		else {
			ll x;
			cin >> x;
			stos.push_back({stos[stos.size() - x - 1].lider, stos[stos.size() - x - 1].value});
		}
		cout << stos.back().value << '\n';
	}

	ll index = stos.size() - 1;
	string answer;
	while(index) {
		if(stos[index].value != '.')
			answer += stos[index].value;
		index = stos[index].lider;
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
	return 0;
}