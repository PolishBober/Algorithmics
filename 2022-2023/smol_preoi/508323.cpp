#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(3e5) + 1

struct Question {
	pair <ll, ll> input;
	ll index, answer;
};

ll tab[MAXN];
ll n, q;
Question questions[MAXN];

#define BASE int(1 << 19)

ll tree[2 * BASE];

void set_point(ll vertex, ll last) {
	vertex += BASE;
	tree[vertex] = last;
	vertex /= 2;
	while(vertex) {
		tree[vertex] = min(tree[2 * vertex], tree[2 * vertex + 1]);
		vertex /= 2;
	}
}

ll query_interval(ll beg) {
	ll vertex = 1;
	while(vertex < BASE) {
		if(tree[2 * vertex] < beg)
			vertex = 2 * vertex;
		else
			vertex = 2 * vertex + 1;
	}
	return vertex - BASE;
}

bool comparator1(const Question &a, const Question &b) {
	return a.input.second < b.input.second;
}

bool comparator2(const Question &a, const Question &b) {
	return a.index < b.index;
}

void solv() {
	ll range = 1;
	for(ll i = 0; i < q; ++i) {
		for(range; range <= questions[i].input.second; ++range)
			set_point(tab[range], range);
		questions[i].answer = query_interval(questions[i].input.first);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for(ll i = 1; i <= n; ++i) {
		cin >> tab[i];
		if(tab[i] > n)
			tab[i] = n + 1;
	}

	for(ll i = 0; i < q; ++i) {
		cin >> questions[i].input.first >> questions[i].input.second;
		questions[i].index = i;
	}

	sort(questions, questions + q, comparator1);

	solv();

	sort(questions, questions + q, comparator2);
	for(ll i = 0; i < q; ++i)
		cout << questions[i].answer << '\n';
	return 0;
}