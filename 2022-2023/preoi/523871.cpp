#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5)
#define BASE int(1 << 19)

struct Description {
	ll min, max;
};

Description tree[2 * BASE];
ll commands[2 * BASE];
ll input[MAXN];
ll n, m;

void prepare() {
	for(auto &t : tree)
		t = {INT_MAX, INT_MIN};
}

void push(ll vertex, ll left, ll right) {
	tree[left].min += commands[vertex];
	tree[left].max += commands[vertex];
	commands[left] += commands[vertex];

	tree[right].min += commands[vertex];
	tree[right].max += commands[vertex];
	commands[right] += commands[vertex];

	commands[vertex] = 0;
}

void set_interval(ll beg, ll end, ll value, ll vertex = 1, ll a = 0, ll b = BASE - 1) {
	if(end < a || b < beg)
		return;
	else if(beg <= a && b <= end) {
		commands[vertex] += value;
		if(tree[vertex].min == INT_MAX) {
			tree[vertex].min = value;
			tree[vertex].max = value;
		}
		else {
			tree[vertex].min += value;
			tree[vertex].max += value;
		}
	}
	else {
		ll left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push(vertex, left, right);
		set_interval(beg, end, value, left, a, mid);
		set_interval(beg, end, value, right, mid + 1, b);
		tree[vertex] = {min(tree[left].min, tree[right].min), max(tree[left].max, tree[right].max)};
	}
}

ll lower_bound(ll value) {
	ll vertex = 1;
	while(vertex < BASE) {
		ll left = 2 * vertex, right = 2 * vertex + 1;
		push(vertex, left, right);
		if(tree[left].max >= value)
			vertex = left;
		else
			vertex = right;
	}
	return vertex - BASE;
}

ll upper_bound(ll value) {
	ll vertex = 1;
	while(vertex < BASE) {
		ll left = 2 * vertex, right = 2 * vertex + 1;
		push(vertex, left, right);
		if(tree[right].min <= value)
			vertex = right;
		else
			vertex = left;
	}
	return vertex - BASE;
}

ll query_point(ll vertex) {
	vertex += BASE;
	ll answer = 0;
	while(vertex) {
		answer += commands[vertex];
		vertex /= 2;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < n; ++i)
		cin >> input[i];

	prepare();

	sort(input, input + n);
	for(ll i = 0; i < n; ++i)
		set_interval(i, i, input[i]);

	for(ll i = 0; i < m; ++i) {
		string type;
		cin >> type;
		if(type == "zbieraj") {
			ll a, b;
			cin >> a >> b;
			if(a > b)
				swap(a, b);
			ll beg = lower_bound(a), end = upper_bound(b);
			if(beg > end || query_point(0) > b)
				cout << 0 << '\n';
			else
				cout << end - beg + 1 << '\n';
		}
		else {
			ll x;
			cin >> x;
			ll value = query_point(x - 1);
			ll first = -1;
			if(value > query_point(0)) {
				first = upper_bound(value - 1);
				set_interval(0, first, 1);
			}
			ll second = n;
			if(query_point(n - 1) > value)
				second = lower_bound(value + 1);

			ll lenght = first + 1;
			set_interval(second - (x - lenght), second - 1, 1);
		}
	}

	return 0;
}