#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Set {
	ll index, value;
};

struct Query {
	ll beg, end, value;
};

#define BASE int(1 << 18)
#define MAXN int(2e5 + 1)

ll tree[2 * BASE];
ll n, m, q, k;
Set changes[MAXN];
Query query[MAXN];

void set_point(ll vertex, ll value) {
	vertex += BASE;
	tree[vertex] += value;
	vertex /= 2;
	while(vertex) {
		tree[vertex] += value;
		vertex /= 2;
	}
}

ll query_interval(ll beg, ll end) {
	beg += BASE;
	end += BASE;
	ll answer = 0;
	while(beg <= end) {
		if(beg % 2)
			answer += tree[beg];
		if(!(end % 2))
			answer += tree[end];
		beg = (beg + 1) / 2;
		end = (end - 1) / 2;
	}
	return answer;
}

bool condition(ll mid) {
	for(ll i = 0; i < mid; ++i)
		set_point(changes[i].index, changes[i].value);

	ll answer = 0;
	for(ll i = 0; i < m; ++i)
		if(query_interval(query[i].beg, query[i].end) >= query[i].value)
			++answer;

	for(ll i = 0; i < mid; ++i)
		set_point(changes[i].index, -changes[i].value);

	return answer >= k;
}

void binsearch() {
	ll beg = -1, end = q + 1;
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(condition(mid))
			end = mid;
		else
			beg = mid;
	}
	if(end == q + 1)
		cout << "NIGDY\n";
	else
		cout << end << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q >> k;
	for(ll i = 0; i < m; ++i)
		cin >> query[i].beg >> query[i].end >> query[i].value;
	for(ll i = 0; i < q; ++i)
		cin >> changes[i].index >> changes[i].value;
	
	binsearch();

	return 0;
}