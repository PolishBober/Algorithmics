#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Coordinates {
	ll y, x;
};

#define MAXN int(5e2) + 1

vector <vector<ll>> board;
ll n;
ll X1, X2, Y1, Y2;

Coordinates right_[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
Coordinates left_[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void write() {
	for(ll i = 0; i <= n; ++i) {
		for(ll j = 0; j <= n; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

void next(ll &x) {
	x = (x + 1) % 4;
}

void check(Coordinates position, ll marker) {
	if(Y1 <= position.y && position.y <= Y2 && X1 <= position.x && position.x <= X2 && !board[position.y - Y1][position.x - X1])
		board[position.y - Y1][position.x - X1] = marker;
}

void final(Coordinates position, Coordinates directions[], ll direction) {
	ll marker = 0;

	check(position, ++marker);
	for(ll i = 0; i < n - 1; ++i) {
		position.y += directions[direction].y;
		position.x += directions[direction].x;
		check(position, ++marker);
	}
	next(direction);

	ll jump = n - 1;
	ll help = 0;
	while(jump) {
		for(ll i = 0; i < jump; ++i) {
			position.y += directions[direction].y;
			position.x += directions[direction].x;
			check(position, ++marker);
		}
		next(direction);
		++help;
		if(help == 2) {
			--jump;
			help = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string a, b;
	cin >> a >> b;
	cin >> X1 >> X2 >> Y1 >> Y2;
	Y1 = n - Y1 + 1;
	Y2 = n - Y2 + 1;
	swap(Y1, Y2);

	for(ll i = 0; i <= Y2 - Y1; ++i) {
		board.push_back({});
		for(ll j = X1; j <= X2; ++j)
			board[i].push_back(0);
	}

	if(b == "PRAWO") {
		if(a == "WSCHOD")
			final({1, 1}, right_, 0);
		else if(a == "POLUDNIE")
			final({1, n}, right_, 1);
		else if(a == "ZACHOD")
			final({n, n}, right_, 2);
		else
			final({n, 1}, right_, 3);
	}
	else {
		if(a == "WSCHOD")
			final({n, 1}, left_, 1);
		else if(a == "POLUDNIE")
			final({1, 1}, left_, 0);
		else if(a == "ZACHOD")
			final({1, n}, left_, 3);
		else
			final({n, n}, left_, 2);
	}

	for(auto line : board) {
		for(auto square : line)
			cout << square << ' ';
		cout << '\n';
	}
	return 0;
}