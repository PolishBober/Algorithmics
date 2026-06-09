#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 101
#define MAXB int(1e4 + 1)

struct Element {
	ll weight, value;
	ll index;
};
static bool operator < (const Element & a, const Element & b) {
	return a.value * b.weight > b.value * a.weight;
}

Element elements[MAXN];
ll dp[MAXB];
ll replay[MAXB];
ll n, b;

void solv() {
	ll answer = 0;
	for(ll i = 0; i < n; ++i) {
		for(ll j = b; j >= elements[i].weight; --j) {
			if(dp[j - elements[i].weight] == 0 && (j - elements[i].weight))
				continue;
			if(dp[j] < dp[j - elements[i].weight] + elements[i].value) {
				dp[j] = dp[j - elements[i].weight] + elements[i].value;
				replay[j] = i;
				if(dp[answer] < dp[j])
					answer = j;
			}
		}
	}
	cout << dp[answer] << '\n';

	vector <ll> use;
	for(ll i = answer; i > 0;) {
		use.push_back(elements[replay[i]].index);
		i -= elements[replay[i]].weight;
	}

	cout << use.size() << '\n';
	for(auto u : use)
		cout << u + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;
	for(ll i = 0; i < n; ++i) {
		elements[i].index = i;
		cin >> elements[i].weight;
	}
	for(ll i = 0; i < n; ++i)
		cin >> elements[i].value;

	sort(elements, elements + n);

	solv();

	return 0;
}