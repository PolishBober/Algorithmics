#include <bits/stdc++.h>
#define ll long long
using namespace std;

queue <ll> todo;
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
			todo.push(number);
		}
		else {
			cout << todo.front() << '\n';
			todo.pop();
		}
	}
}