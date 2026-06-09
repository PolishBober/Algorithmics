#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(25e4) + 1

ll delivery[MAXN];
ll order[MAXN];

ll n;

void solv() {
	priority_queue <ll> answer;
	ll sum = 0;
	for(ll i = 1; i <= n; ++i) {
		if(delivery[i] - sum >= order[i]) {
			sum += order[i];
			answer.push(order[i]);
		}
		else if(!answer.empty() && order[i] < answer.top()) {
			sum += -answer.top() + order[i];
			answer.pop();
			answer.push(order[i]);
		}
	}
	cout << answer.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i) {
		cin >> delivery[i];
		delivery[i] += delivery[i - 1];
	}
	for(ll i = 1; i <= n; ++i)
		cin >> order[i];

	solv();

	return 0;
}