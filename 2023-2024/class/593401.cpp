#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Interval {
	ll beg, end;
	ll index;
};

#define MAXN int(5e5 + 7)

Interval intervals[MAXN];
ll n;


// ll solv() {
// 	ll backup = 0;
// 	ll actual = 1;
// 	for(ll backup = 0; backup < )
// }

vector <ll> answer1;
void floor() {
	answer1.push_back(intervals[0].index);
	ll last = 0;
	for(ll i = 1; i < n; ++i) {
		if(intervals[i].beg >= intervals[last].end) {
			last = i;
			answer1.push_back(intervals[i].index);
		}
	}
}

bool condition(Interval a, Interval b) {
	return a.end < b.end;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		cin >> intervals[i].beg >> intervals[i].end;
		intervals[i].index = i;
	}
	
	sort(intervals, intervals + n, condition);

	floor();

	cout << answer1.size() << '\n';

	return 0;
}