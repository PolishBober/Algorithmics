#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Coordinates {
	int y, x;
	int level;
};
static bool operator < (const Coordinates & a, const Coordinates & b) {
	if(a.y + a.x == b.y + b.x)
		return a.y < b.y;
	return a.y + a.x > b.y + b.x;
}

bool condition(const Coordinates & a, const Coordinates & b) {
	return a.y > b.y;
}

#define BASE int(1 << 20)

int tree[2 * BASE];

void set_point(int vertex, int value) {
	vertex += BASE;
	tree[vertex] = value;
	vertex /= 2;
	while(vertex) {
		tree[vertex] = max(tree[2 * vertex], tree[2 * vertex + 1]);
		vertex /= 2;
	}
}

int query_interval(int beg, int end) {
	beg += BASE;
	end += BASE;
	int answer = 0;
	while(beg <= end) {
		if(beg % 2)
			answer = max(answer, tree[beg]);
		if(!(end % 2))
			answer = max(answer, tree[end]);
		beg = (beg + 1) / 2;
		end = (end - 1) / 2;
	}
	return answer;
}


#define MAXN int(1e6 + 1)

Coordinates input[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> input[i].x >> input[i].y;

	sort(input, input + n, condition);
	for(int i = 1; i < n; ++i) {
		if(input[i].y == input[i - 1].y)
			input[i].level = input[i - 1].level;
		else
			input[i].level = input[i - 1].level + 1;
	}

	sort(input, input + n);

	for(int i = 0; i < n; ++i)
		set_point(input[i].level, query_interval(input[i].level, n + 1) + 1);

	cout << query_interval(0, n + 1) << '\n';

	return 0;
}