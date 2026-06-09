#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(2e5) + 1

ll n, m;

struct Area {
	ll x1, y1, x2, y2;
};
static bool operator < (const Area &a, const Area &b) {
	return a.x1 < b.x1;
}
Area areas[MAXN];

struct Question {
	ll x, y1, y2;
	ll index, answer;
};
bool comparator1(const Question &a, const Question &b) {
	return a.x < b.x;
}
bool comparator2(const Question &a, const Question &b) {
	return a.index < b.index;
}
Question questions[MAXN];

#define POWER 17
#define BASE int(1 << POWER)

pair <ll, ll> tree[2 * BASE];
ll commands[2 * BASE];

void push(ll vertex, ll left, ll right) {
	tree[left].first += commands[vertex];
	commands[left] += commands[vertex];

	tree[right].first += commands[vertex];
	commands[right] += commands[vertex];

	commands[vertex] = 0;
}

void set_interval(ll beg, ll end, ll value, ll vertex = 1, ll a = 1, ll b = BASE) {
	if(end < a || b < beg)
		return;
	else if(beg <= a && b <= end) {
		tree[vertex].first += value;
		commands[vertex] += value;
		if(!tree[vertex].second)
			tree[vertex].second = b-a+1;
	}
	else {
		ll left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push(vertex, left, right);
		set_interval(beg, end, value, left, a, mid);
		set_interval(beg, end, value, right, mid + 1, b);
		if(tree[left].first == tree[right].first)
			tree[vertex] = {tree[left].first, tree[left].second + tree[right].second};
		else if(tree[left].first < tree[right].first)
			tree[vertex] = tree[left];
		else
			tree[vertex] = tree[right];
	}
}

ll query_interval(ll beg, ll end, ll vertex = 1, ll a = 1, ll b = BASE) {
	if(end < a || b < beg || tree[vertex].first)
		return 0;
	else if(beg <= a && b <= end)
		return tree[vertex].second;
	else {
		ll left = 2 * vertex, right = 2 * vertex + 1, mid = (a + b) / 2;
		push(vertex, left, right);
		return query_interval(beg, end, left, a, mid) + query_interval(beg, end, right, mid + 1, b);
	}
}

struct Description {
	ll last, index;
	friend bool operator < (const Description & a, const Description & b) {
		return a.last > b.last;
	}
};

void solv() {
	for(ll i = 0; i <= POWER; ++i)
		for(ll j = 1 << i; j < 1 << (i + 1); ++j)
			tree[j].second = 1 << (POWER - i);
	priority_queue <Description> todo;
	ll x = 1;
	ll beg = 0;
	ll q = 0;
	while(q < m) {
		while(!todo.empty() && todo.top().last < x) {
			auto top = todo.top();
			todo.pop();
			set_interval(areas[top.index].y1, areas[top.index].y2, -1);
		}
		while(beg < n && areas[beg].x1 <= x) {
			set_interval(areas[beg].y1, areas[beg].y2, 1);
			todo.push({areas[beg].x2, beg});
			++beg;
		}
		while(q < m && questions[q].x == x) {
			questions[q].answer = query_interval(questions[q].y1, questions[q].y2);
			++q;
		}
		++x;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(ll i = 0; i < n; ++i) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2)
			swap(x1, x2);
		if(y1 > y2)
			swap(y1, y2);
		areas[i] = {x1, y1, x2, y2};
	}
	sort(areas, areas + n);

	for(ll i = 0; i < m; ++i) {
		ll x, y1, y2;
		cin >> x >> y1 >> y2;
		if(y1 > y2)
			swap(y1, y2);
		questions[i] = {x, y1, y2, i};
	}
	sort(questions, questions + m, comparator1);

	solv();

	sort(questions, questions + m, comparator2);

	for(ll i = 0; i < m; ++i)
		cout << questions[i].answer << ' ';

	return 0;
}