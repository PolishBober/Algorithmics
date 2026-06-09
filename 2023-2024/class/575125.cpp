#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(25e4 + 1)

ll delivery[MAXN];
ll requests[MAXN];
ll n;

void solv() {
	priority_queue <ll> todo;
	ll magazine = 0;
	for(ll i = 0; i < n; ++i) {
		magazine += delivery[i];
		if(requests[i] <= magazine) {
			magazine -= requests[i];
			todo.push(requests[i]);
		}
		else if(!todo.empty() && todo.top() > requests[i]) {
			magazine += todo.top() - requests[i];
			todo.pop();
			todo.push(requests[i]);
		}
	}
	cout << todo.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i)
		cin >> delivery[i];
	for(ll i = 0; i < n; ++i)
		cin >> requests[i];

	solv();

	return 0;
}