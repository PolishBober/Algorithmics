#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Tank {
	ll volume, value;
};
static bool operator < (const Tank & a, const Tank & b) {
	return double(a.value) / a.volume > double(b.value) / b.volume;
}

#define MAXN int(2e5 + 1)

Tank tanks[MAXN];
ll n, v;

void solv() {
	sort(tanks, tanks + n);

	double value = 0;
	ll volume = 0;
	for(ll i = 0; i < n; ++i) {
		if(volume + tanks[i].volume <= v) {
			value += tanks[i].value;
			volume += tanks[i].volume;
		}
		else {
			value += (double(tanks[i].value) / tanks[i].volume) * (v - volume);
			break;
		}
	}
	cout << setprecision(7) << fixed << value << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> v;
	for(ll i = 0; i < n; ++i)
		cin >> tanks[i].volume;
	for(ll i = 0; i < n; ++i)
		cin >> tanks[i].value;

	solv();

	return 0;
}