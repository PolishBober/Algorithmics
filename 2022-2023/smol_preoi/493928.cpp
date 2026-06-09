#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Coordinates {
	ll x, y, z;
	ll a, b;
};
static bool operator == (const Coordinates & a, const Coordinates & b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
static bool operator < (const Coordinates & a, const Coordinates & b) {
	if(a.x == b.x) {
		if(a.y == b.y)
			return a.z < b.z;
		return a.y < b.y;
	}
	return a.x < b.x;
}

set <Coordinates> instruments;
ll constant;
ll xsum, ysum, zsum, asum;
ll q;

void add(ll x, ll y, ll z, ll a, ll b) {
	instruments.insert({x, y, z, a, b});
	constant += a * (x*x + y*y + z*z) + b;
	xsum += 2 * a * x;
	ysum += 2 * a * y;
	zsum += 2 * a * z;
	asum += a;
}

void del(ll x, ll y, ll z) {
	auto index = instruments.find(Coordinates{x, y, z});
	constant -= (*index).a * (x*x + y*y + z*z) + (*index).b;
	xsum -= 2 * (*index).a * x;
	ysum -= 2 * (*index).a * y;
	zsum -= 2 * (*index).a * z;
	asum -= (*index).a;
	instruments.erase(Coordinates{x, y, z});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> q;
	for(ll i = 0; i < q; ++i) {
		char type;
		ll x, y, z, a, b;
		cin >> type >> x >> y >> z;
		if(type == 'D') {
			cin >> a >> b;
			add(x, y, z, a, b);
		}
		else if(type == 'U')
			del(x, y, z);
		else
			cout << constant - x * xsum - y * ysum - z * zsum + (x*x + y*y + z*z) * asum << '\n';
	}
}