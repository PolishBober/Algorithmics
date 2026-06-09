#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Scale {
	unsigned ll number;
	ll index;
};
static bool operator < (const Scale & scale1, const Scale & scale2) {
	if(scale1.number == scale2.number)
		return scale1.index > scale2.index;
	return scale1.number < scale2.number;
}

const ll maxn = 1e5;
Scale scale[maxn];
ll tab[maxn];
ll n;

const ll base = 1<<17;
ll tree[2 * base];

void set_interval(ll beg, ll end, ll value) {
	beg += base;
	end += base;
	while(beg <= end) {
		if(beg % 2)
			tree[beg] += value;
		if(!(end % 2))
			tree[end] += value;
		beg = (beg + 1) / 2;
		end = (end - 1) / 2;
	}
}

ll query_point(ll vertex) {
	vertex += base;
	ll answer = 0;
	while(vertex) {
		answer += tree[vertex];
		vertex /= 2;
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		cin >> scale[i].number;
		scale[i].index = n - i - 1;
	}


	sort(scale, scale + n);
	for(ll i = 0; i < n; ++i)
		tab[scale[i].index] = i;

	ll answer = 0;
	for(ll i = 0; i < n; ++i) {
		answer += query_point(tab[i]);
		set_interval(tab[i] + 1, n - 1, 1);
	}
	cout << answer;
}