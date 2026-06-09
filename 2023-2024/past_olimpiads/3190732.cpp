#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define BASE int(1 << 19)

ll tree[2 * BASE];
ll commands[2 * BASE];


void push(ll vertex) {
	tree[2 * vertex] += commands[vertex];
	commands[2 * vertex] += commands[vertex];

	tree[2 * vertex + 1] += commands[vertex];
	commands[2 * vertex + 1] += commands[vertex];

	commands[vertex] = 0;
}

void set_interval(ll beg, ll end, ll value, ll index = -1, ll vertex = 1, ll a = 0, ll b = BASE - 1) {
	if(beg <= a && b <= end) {
		tree[vertex] += value;
		commands[vertex] += value;
	}
	else if(a <= beg && beg <= b || a <= end && end <= b) {
		push(vertex);
		ll mid = (a + b) / 2;
		set_interval(beg, end, value, index, 2 * vertex, a, mid);
		set_interval(beg, end, value, index, 2 * vertex + 1, mid + 1, b);
		
		tree[vertex] = max(tree[2 * vertex], tree[2 * vertex + 1]);
	}
}



#define MAXN int(5e5 + 7)

ll weights[MAXN];
ll sum;
ll n;


map <ll, ll> available;
void find_points(ll vertex = 1) {
	if(vertex >= BASE) {
		available[-weights[vertex - BASE]] = vertex - BASE;
		return;
	}

	push(vertex);
	if(tree[2 * vertex] > 0)
		find_points(2 * vertex);
	if(tree[2 * vertex + 1] > 0)
		find_points(2 * vertex + 1);

	tree[vertex] = max(tree[2 * vertex], tree[2 * vertex + 1]);
}



void solv() {
	vector <ll> answer = {sum};

	for(ll i = 1; i < n; ++i) {
		find_points();

		pair <ll, ll> top = *available.begin();
		top.first *= -1;

		answer.push_back(answer.back() - top.first);

		set_interval(top.second, top.second, -LLONG_MAX);
		set_interval(0, top.second - 1, top.first);

		available.erase(-top.first);
	}

	reverse(answer.begin(), answer.end());

	for(auto a : answer)
		cout << a << ' ';
	cout << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i) {
		cin >> weights[i];
		sum += weights[i];
		set_interval(i, i, weights[i], i);
		set_interval(0, i - 1, -weights[i]);
	}

	solv();

	return 0;
}