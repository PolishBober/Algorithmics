#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define BASE int(1 << 20)

ll tree[2 * BASE];
ll sum;
ll n, k;

void set_point(ll vertex, ll value) {
	vertex += BASE;
	ll change = value - tree[vertex];
	sum += change;
	tree[vertex] = value;
	vertex /= 2;
	while(vertex) {
		tree[vertex] += change;
		vertex /= 2;
	}
}

void find() {
	ll vertex = 1;
	ll value = tree[1] / 2;
	ll interval = 0;
	while(vertex < BASE) {
		if(tree[2 * vertex] >= value)
			vertex = 2 * vertex;
		else {
			interval += tree[2 * vertex];
			value -= tree[2 * vertex];
			vertex = 2 * vertex + 1;
		}
	}
	cout << min(abs(2 * interval - sum), abs(2 * (interval + tree[vertex]) - sum)) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(ll i = 0; i < 2 * BASE; ++i)
		tree[i] = 0;

	cin >> n;
	for(ll i = 0; i < n - 1; ++i) {
		ll help;
		cin >> help;
		set_point(i, help);
	}

	find();

	cin >> k;
	for(ll i = 0; i < k; ++i) {
		ll a, b;
		cin >> a >> b;
		set_point(a - 1, b);
		find();
	}

	return 0;
}