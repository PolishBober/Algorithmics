#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define BASE int(1 << 20)

ll tree_count[2 * BASE];
ll tree_size[2 * BASE];

void set_point(ll vertex, ll value, ll (&tree)[2 * BASE]) {
	vertex += BASE;
	tree[vertex] += value;
	vertex /= 2;
	while(vertex) {
		tree[vertex] += value;
		vertex /= 2;
	}
}

ll query_interval(ll beg, ll end, ll (&tree)[2 * BASE]) {
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

pair <ll, ll> find(ll value, ll (&tree)[2 * BASE]) {
	ll vertex = 1;

	while(vertex < BASE) {
		if(tree[2 * vertex + 1] < value) {
			value -= tree[2 * vertex + 1];
			vertex = 2 * vertex;
		}
		else
			vertex = 2 * vertex + 1;
	}
	return {vertex - BASE, value};
}


#define MAXN int(2e5 + 7)

struct Description {
	ll count, size;
};

pair <ll, ll> input[MAXN];
vector <Description> domino;


Description big;
Description low;
ll n;




ll need;
ll sum;

bool condition() {

	if(need > big.count) {
		if(sum - big.count * big.size <= low.count)
			return true;
		return false;
	}


	pair <ll, ll> out = find(big.count - need, tree_count);

	if(query_interval(0, out.first - 1, tree_size) + (tree_count[out.first + BASE] - out.second) * out.first <= low.count)
		return true;
	return false;

}

ll solv() {
	ll answer = 0;

	ll value = big.count + low.count;

	// cout << 'x' << '\n';


	ll end = 0;
	for(ll beg = 0; beg < domino.size(); ++beg) {

		value += domino[beg].count;

		// cout << end << ' ' << beg << '\n';


		while(!condition()) {
			set_point(domino[end].size % big.size, -1, tree_count);
			set_point(domino[end].size % big.size, -(domino[end].size % big.size), tree_size);

			value -= domino[end].count;
			need -= domino[end].size / big.size;
			sum -= domino[end].size;

			++end;
		}

		// cout << end << ' ' << beg << '\n';
		// cout << value << '\n';

		set_point(domino[beg].size % big.size, 1, tree_count);
		set_point(domino[beg].size % big.size, domino[beg].size % big.size, tree_size);
		
		need += domino[beg].size / big.size;
		sum += domino[beg].size;

		answer = max(answer, value);
	}

	return answer;
}




void prep1(ll div) {
	ll range = 0;
	ll capacity = 0;
	for(ll i = 1; i < n; ++i) {
		++capacity;
		range = max(range, input[i].first + input[i].second);
		if(range >= input[i + 1].first)
			continue;

		domino.push_back({capacity, ceil((input[i + 1].first - range) / double(div))});
		capacity = 0;
	}
	++capacity;
	domino.push_back({capacity, 0});
}
void prep2(ll div) {
	domino.clear();
	for(ll i = 0; i < 2 * BASE; ++i) {
		tree_size[i] = 0;
		tree_count[i] = 0;
	}
	need = 0;
	sum = 0;

	ll range = LLONG_MAX;
	ll capacity = 0;
	for(ll i = 1; i < n; ++i) {
		++capacity;
		range = min(range, input[i].first - input[i].second);
		if(range <= input[i + 1].first)
			continue;

		domino.push_back({capacity, ceil((range - input[i + 1].first) / double(div))});
		capacity = 0;
	}
	++capacity;
	domino.push_back({capacity, 0});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 1; i <= n; ++i)
		cin >> input[i].first >> input[i].second;
	cin >> big.count >> big.size >> low.count >> low.size;
	if(big.size < low.size)
		swap(big, low);

	ll nwd = low.size;
	big.size /= nwd;
	low.size /= nwd;


	prep1(nwd);
	ll answer = solv();

	reverse(input + 1, input + n + 1);

	prep2(nwd);
	answer = max(answer, solv());

	cout << answer << '\n';

	return 0;
}