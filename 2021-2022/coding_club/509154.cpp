#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline void readUI(ll *n) //tylko dodatnie
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

#define BASE int(1 << 18)

ll tree1[2 * BASE];
ll tree2[2 * BASE];
ll commands1[2 * BASE];
ll commands2[2 * BASE];
ll n, m, g2, g1;

void push1(ll vertex, ll left, ll right) {
	tree1[left] += commands1[vertex];
	commands1[left] += commands1[vertex];

	tree1[right] += commands1[vertex];
	commands1[right] += commands1[vertex];

	commands1[vertex] = 0;
}

void push2(ll vertex, ll left, ll right) {
	tree2[left] += commands2[vertex];
	commands2[left] += commands2[vertex];

	tree2[right] += commands2[vertex];
	commands2[right] += commands2[vertex];

	commands2[vertex] = 0;
}

void set_interval1(ll beg, ll end, ll value, ll vertex = 1, ll a = 1, ll b = BASE) {
	if(end < a || b < beg)
		return;
	else if(beg <= a && b <= end) {
		tree1[vertex] += value;
		commands1[vertex] += value;
	}
	else {
		ll left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push1(vertex, left, right);
		set_interval1(beg, end, value, left, a, mid);
		set_interval1(beg, end, value, right, mid + 1, b);
		tree1[vertex] = max(tree1[left], tree1[right]);
	}
}

void set_interval2(ll beg, ll end, ll value, ll vertex = 1, ll a = 1, ll b = BASE) {
	if(end < a || b < beg)
		return;
	else if(beg <= a && b <= end) {
		tree2[vertex] += value;
		commands2[vertex] += value;
	}
	else {
		ll left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push2(vertex, left, right);
		set_interval2(beg, end, value, left, a, mid);
		set_interval2(beg, end, value, right, mid + 1, b);
		tree2[vertex] = max(tree2[left], tree2[right]);
	}
}

ll query_interval1(ll beg, ll end, ll vertex = 1, ll a = 1, ll b = BASE) {
	if(end < a || b < beg || tree1[vertex] < 0)
		return 0;
	else if(vertex >= BASE) {
		set_interval1(a, b, LLONG_MIN);
		return b-a+1;
	}
	else {
		ll left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push1(vertex, left, right);
		return query_interval1(beg, end, left, a, mid) + query_interval1(beg, end, right, mid + 1, b);
	}
}

ll query_interval2(ll beg, ll end, ll vertex = 1, ll a = 1, ll b = BASE) {
	if(end < a || b < beg || tree2[vertex] < 0)
		return 0;
	else if(vertex >= BASE) {
		set_interval2(a, b, LLONG_MIN);
		return b-a+1;
	}
	else {
		ll left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push2(vertex, left, right);
		return query_interval2(beg, end, left, a, mid) + query_interval2(beg, end, right, mid + 1, b);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	readUI(&n);
	readUI(&m);
	readUI(&g2);
	readUI(&g1);
	set_interval1(1, n, -g1);
	set_interval2(1, n, -g2);
	for(ll i = 1; i <= n; ++i) {
		ll k;
		readUI(&k);
		set_interval1(i, i, k);
		set_interval2(i, i, k);
	}
	g1 = 0;
	g2 = 0;
	for(ll i = 0; i < m; ++i) {
		ll a, b, x;
		readUI(&a);
		readUI(&b);
		readUI(&x);
		set_interval1(1, n, 1);
		set_interval2(1, n, 1);
		set_interval1(a, b, x);
		set_interval2(a, b, x);
		g1 += query_interval1(1, n);
		g2 += query_interval2(1, n);
		printf("%d %d\n", g1, g2 - g1);
	}
	return 0;
}