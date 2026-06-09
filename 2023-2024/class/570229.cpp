#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll board[9][9];
bool vertical[9][10];
bool horizontal[9][10];


bool check(ll y, ll x) {
	if(vertical[x][board[y][x]])
		return false;
	if(horizontal[y][board[y][x]])
		return false;

	ll ystart = y - y % 3;
	ll xstart = x - x % 3;
	for(ll i = 0; i < 3; ++i)
		for(ll j = 0; j < 3; ++j)
			if(board[ystart + i][xstart + j] == board[y][x] && ystart + i != y && xstart + j != x)
				return false;

	return true;
}


bool theend;
void solv(ll y, ll x) {
	for(ll i = y; i < 9; ++i) {
		for(ll j = x + 1; j < 9; ++j) {
			if(board[i][j] == -1) {
				y = i;
				x = j;
				goto next;
			}
		}
		x = -1;
	}
	next:

	if(x == -1) {
		theend = true;
		return;
	}

	for(ll i = 1; i <= 9; ++i) {
		board[y][x] = i;
		if(check(y, x)) {
			vertical[x][i] = true;
			horizontal[y][i] = true;
			solv(y, x);
			if(theend)
				return;
			vertical[x][i] = false;
			horizontal[y][i] = false;
		}
		board[y][x] = -1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(ll i = 0; i < 9; ++i) {
		for(ll j = 0; j < 9; ++j) {
			char help;
			cin >> help;
			if(help == '*')
				board[i][j] = -1;
			else {
				board[i][j] = help - '0';
				vertical[j][board[i][j]] = true;
				horizontal[i][board[i][j]] = true;
			}
		}
	}

	solv(0, -1);

	for(ll i = 0; i < 9; ++i) {
		for(ll j = 0; j < 9; ++j)
			cout << board[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}