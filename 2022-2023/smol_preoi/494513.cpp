#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Section {
	ll l, v;
};

const ll maxn = 1e5;
Section highway[maxn];
ll n, t;

bool condition(double mid) {
	double time = 0;
	for(ll i = 0; i < n; ++i)
		time += highway[i].l / (highway[i].v + mid);
	return time <= t;
}

void binsearch() {
	double beg = 0, end = 5e4;
	while(end - beg > 0.00001) {
		double mid = (beg + end) / 2;
		if(condition(mid))
			end = mid;
		else
			beg = mid;
	}
	cout << setprecision(5) << fixed << end;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	for(ll i = 0; i < n; ++i)
		cin >> highway[i].l >> highway[i].v;

	binsearch();
	return 0;
}
