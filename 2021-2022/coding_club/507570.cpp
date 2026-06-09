#include <bits/stdc++.h>
using namespace std;

#define BASE int(1 << 20)

int tree[2 * BASE];
int commands[2 * BASE];

int d, n;

void push(int vertex, int left, int right) {
	if(commands[vertex]) {
		tree[left] = commands[vertex];
		commands[left] = commands[vertex];

		tree[right] = commands[vertex];
		commands[right] = commands[vertex];

		commands[vertex] = 0;
	}
}

void set_interval(int beg, int end, int value, int vertex = 1, int a = 1, int b = BASE) {
	if(end < a || b < beg)
		return;
	else if(beg <= a && b <= end) {
		tree[vertex] = value;
		commands[vertex] = value;
	}
	else {
		int left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push(vertex, left, right);
		set_interval(beg, end, value, left, a, mid);
		set_interval(beg, end, value, right, mid + 1, b);
		tree[vertex] = max(tree[left], tree[right]);
	}
}

int query_interval(int beg, int end, int vertex = 1, int a = 1, int b = BASE) {
	if(end < a || b < beg)
		return 0;
	else if(beg <= a && b <= end)
		return tree[vertex];
	else {
		int left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push(vertex, left, right);
		return max(query_interval(beg, end, left, a, mid), query_interval(beg, end, right, mid + 1, b));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> d >> n;
	for(int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		swap(a, b);
		b += a;
		++a;
		set_interval(a, b, query_interval(a, b) + 1);
	}
	cout << query_interval(1, d + 1);
}