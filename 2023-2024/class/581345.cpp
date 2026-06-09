#include <bits/stdc++.h>
using namespace std;

struct Node {
	int value;
	int pointer;
};

struct Coordinates {
	int y, x;
};

int board[6][6];
Node answer[6][6];
int n;
int turn;

vector <pair<int, int>> directions = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
bool theend;

bool prep() {
	for(int y = 0; y < n; ++y)
		for(int x = 0; x < n; ++x)
			answer[y][x].pointer = -1;

	for(int y = 0; y < n; ++y) {
		for(int x = 0; x < n; ++x) {
			if(y == n - 1 && x == n - 1 || answer[y][x].value)
				continue;

			int direction = board[y][x];
			int limit = INT_MAX;
			if(directions[direction].first < 0)
				limit = min(limit, y);
			else if(directions[direction].first > 0)
				limit = min(limit, n - y - 1);
			if(directions[direction].second < 0)
				limit = min(limit, x);
			else if(directions[direction].second > 0)
				limit = min(limit, n - x - 1);

			int count = 0;
			Coordinates last;
			int saveY = y, saveX = x;
			for(; limit > 0; --limit) {
				saveY += directions[direction].first;
				saveX += directions[direction].second;
				if(!answer[saveY][saveX].value && !(answer[saveY][saveX].pointer >= 0 && answer[saveY][saveX].pointer != direction)) {
					++count;
					last = {saveY, saveX};
				}
			}
			if(count == 1)
				answer[last.y][last.x].pointer = direction;
			if(!count)
				return true;
		}
	}
	return false;
}

void solv(int y, int x, int value) {
	if(y == n - 1 && x == n - 1 && value == n*n + 1) {
		theend = true;
		return;
	}

	int backup[6][6];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			backup[i][j] = answer[i][j].pointer;
	
	if(prep())
		return;

	int direction = board[y][x];

	int limit = INT_MAX;
	if(directions[direction].first < 0)
		limit = min(limit, y);
	else if(directions[direction].first > 0)
		limit = min(limit, n - y - 1);
	if(directions[direction].second < 0)
		limit = min(limit, x);
	else if(directions[direction].second > 0)
		limit = min(limit, n - x - 1);

	for(int i = limit; i > 0; --i) {
		y += directions[direction].first;
		x += directions[direction].second;

		if(!answer[y][x].value && !(answer[y][x].pointer >= 0 && answer[y][x].pointer != direction)) {

			answer[y][x].value = value;

			solv(y, x, value + 1);

			if(theend)
				return;

			answer[y][x].value = 0;
		}
		if(answer[y][x].pointer == direction)
			break;
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			answer[i][j].pointer = backup[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin >> n) {
		++turn;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				string help;
				cin >> help;
				if(help == "N")
					board[i][j] = 0;
				else if(help == "NE")
					board[i][j] = 1;
				else if(help == "E")
					board[i][j] = 2;
				else if(help == "SE")
					board[i][j] = 3;
				else if(help == "S")
					board[i][j] = 4;
				else if(help == "SW")
					board[i][j] = 5;
				else if(help == "W")
					board[i][j] = 6;
				else if(help == "NW")
					board[i][j] = 7;
				else
					board[i][j] = -1;
			}
		}

		answer[0][0].value = 1;
		theend = false;
		solv(0, 0, 2);

		printf("Case #%i:\n", turn);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				printf("%i ", answer[i][j].value);
				answer[i][j].value = 0;
			}
			printf("\n");
		}
	}

	return 0;
}