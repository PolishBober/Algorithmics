#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6 + 2)

map <int, int> last;
int n, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	ll actual = 0;
	ll answer = 0;
	++last[actual];
	for(int i = 1; i <= n; ++i) {
		ll help;
		cin >> help;
		actual ^= help;
		answer += last[actual ^ k];
		++last[actual];
	}

	cout << answer << '\n';

	return 0;
}