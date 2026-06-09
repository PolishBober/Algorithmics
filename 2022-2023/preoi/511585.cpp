#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(2e4) + 3
// 14 + 1

vector <int> graph[MAXN];
int fathers[MAXN];
int pre[MAXN];
int _pre[MAXN];
int order;
int n, q;
ll m;

void dfs(int vertex) {
	pre[vertex] = ++order;
	_pre[order] = vertex;
	for(auto edge : graph[vertex]) {
		if(!pre[edge]) {
			fathers[edge] = vertex;
			dfs(edge);
		}
	}
}

struct Node {
	int id;
	bool factory;
	int weight;
};
static bool operator < (const Node &a, const Node &b) {
	return pre[a.id] < pre[b.id];
}
Node nodes[MAXN];

struct Question {
	int x, t;
	ll k;
	int index;
	ll answer;
};
bool comparator1(const Question &a, const Question &b) {
	return pre[a.x] < pre[b.x];
}
bool comparator2(const Question &a, const Question &b) {
	return a.index < b.index;
}
Question questions[MAXN];

#define BASE int(1 << 14)

int tree[2 * BASE];

void set_interval(int beg, int end, int value) {
	beg += BASE;
	end += BASE;
	while(beg <= end) {
		if(beg % 2)
			tree[beg] += value;
		if(!(end % 2))
			tree[end] += value;
		beg = (beg + 1) / 2;
		end = (end - 1) / 2;
	}
}

int query_point(int vertex) {
	int answer = 0;
	while(vertex < BASE) {
		answer += tree[vertex];
		vertex = 2 * vertex;
	}
	return answer + tree[vertex];
}

int query_binsearch(int t) {
	int vertex = 1;
	int sum = tree[vertex];
	while(vertex < BASE) {
		if(sum + query_point(2 * vertex + 1) >= t) {
			vertex = 2 * vertex + 1;
			sum += tree[vertex];
		}
		else {
			vertex = 2 * vertex;
			sum += tree[vertex];
		}
	}
	return vertex - BASE;
}

#define EPS (long double)(1e-9)
void solv() {
	int beg = 0;
	vector <int> path;
	for(int i = 1; i <= n; ++i) {
		while(!path.empty() && pre[fathers[_pre[i]]] != path.back()) {
			set_interval(0, nodes[path.back()].weight, -1);
			path.pop_back();
		}
		set_interval(0, nodes[i].weight, 1);
		path.push_back(i);
		while(beg < q && pre[questions[beg].x] == i) {
			int weight = query_binsearch(questions[beg].t);
			if(!weight)
				questions[beg].answer = -1;
			else
				questions[beg].answer = (sqrt(1 + 4 * 2 * double(questions[beg].k) / weight) + 1) / 2 - EPS;
			++beg;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> nodes[i].factory;
		nodes[i].id = i;
	}

	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1; i <= n; ++i) {
		if(nodes[i].factory) {
			++nodes[i].weight;
			for(auto edge : graph[i])
				++nodes[edge].weight;
		}
	}

	fathers[1] = 1;
	dfs(1);

	cin >> q;
	for(int i = 0; i < q; ++i) {
		cin >> questions[i].x >> questions[i].t >> questions[i].k;
		questions[i].index = i;
	}

	sort(questions, questions + q, comparator1);
	sort(nodes + 1, nodes + n + 1);

	solv();

	sort(questions, questions + q, comparator2);

	for(int i = 0; i < q; ++i)
		cout << questions[i].answer << '\n';

	return 0;
}