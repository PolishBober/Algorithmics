#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline void readUI(int *n) //tylko dodatnie
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

#define MAXN int(1e6) + 1

struct Question {
	pair <int, int> input;
	int index, answer;
};

int tab[MAXN];
int n, q;
Question questions[MAXN];

#define BASE int(1 << 20)

int tree[2 * BASE];

void set_point(int vertex, int last) {
	vertex += BASE;
	tree[vertex] = last;
	vertex /= 2;
	while(vertex) {
		tree[vertex] = min(tree[2 * vertex], tree[2 * vertex + 1]);
		vertex /= 2;
	}
}

int query_interval(int beg) {
	int vertex = 1;
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
	int range = 1;
	for(int i = 0; i < q; ++i) {
		for(range; range <= questions[i].input.second; ++range)
			set_point(tab[range], range);
		questions[i].answer = query_interval(questions[i].input.first);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// cin >> n;
	readUI(&n);
	for(int i = 1; i <= n; ++i) {
		// cin >> tab[i];
		readUI(&tab[i]);
		if(tab[i] > n)
			tab[i] = n + 1;
	}

	// cin >> q;
	readUI(&q);
	for(int i = 0; i < q; ++i) {
		// cin >> questions[i].input.first >> questions[i].input.second;
		readUI(&questions[i].input.first);
		readUI(&questions[i].input.second);
		questions[i].index = i;
	}

	sort(questions, questions + q, comparator1);

	solv();

	sort(questions, questions + q, comparator2);
	for(int i = 0; i < q; ++i)
		cout << questions[i].answer << '\n';
	return 0;
}