#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool tab[101][101];
ll n;

void box(int y, int x) {
	tab[y][x] = true;
	tab[y + 1][x] = true;
	tab[y][x + 1] = true;
	tab[y + 1][x + 1] = true;
}

void mul() {
	int y = 0, x = 0;
	while(y < 95 && x < 95) {
		box(y, x);
		y += 2;
		x += 1;
		box(y, x);
		y += 1;
		x += 2;
	}
}

void line(int y = -1, int x = -1) {
	if(y >= 0) {
		for(int i = y; i < 100; ++i)
			tab[y][i] = true;
	}
	if(x >= 0) {
		for(int i = x; i < 100; ++i)
			tab[i][x] = true;
	}
}

void add() {
	ll y = 0, x = 1;
	while(y < 94) {
		if((((ll)1 << (y / 3 * 2)) & n) == ((ll)1 << (y / 3 * 2)))
			line(y, -1);
		y += 3;
	}
	while(x < 94) {
		if((((ll)1 << (x / 3 * 2 + 1)) & n) == ((ll)1 << (x / 3 * 2 + 1)))
			line(-1, x);
		x += 3;
	}
	for(ll i = 0; i < 100; ++i) {
		tab[i][99] = true;
		tab[99][i] = true;	
	}
}

void draw() {
	for(ll i = 0; i < 100; ++i) {
		for(ll j = 0; j < 100; ++j) {
			if(tab[i][j])
				cout << '.';
			else
				cout << '#';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	mul();
	add();

	cout << 100 << '\n';
	draw();

	return 0;
}