#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXX 123 + 2
#define MAXN 1860867 + 1

struct Coordinates {
	ll z, y, x;
};

bool board[MAXX][MAXX][MAXX];
vector <int> lifts[MAXN];
int distances[MAXX][MAXX][MAXX];
deque <Coordinates> todo;
int x, y, z;
int m;

int convert(Coordinates a) {
	return (a.z - 1) * 15129 + (a.y - 1) * 123 + a.x - 1;
}

Coordinates deconvert(int a) {
	return {a / 15129 + 1, (a % 15129) / 123 + 1, (a % 15129) % 123 + 1};
}

void bfs(Coordinates vertex) {
	Coordinates directions[4] = {{0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
	for(auto &i : distances)
		for(auto &j : i)
			for(auto &k : j)
				k = -1;
	distances[vertex.z][vertex.y][vertex.x] = 0;
	todo.push_back(vertex);
	while(!todo.empty()) {
		auto top = todo.front();
		todo.pop_front();
		for(auto lift : lifts[convert(top)]) {
			Coordinates help = deconvert(lift);
			if(distances[help.z][help.y][help.x] < 0 && board[help.z][help.y][help.x]) {
				distances[help.z][help.y][help.x] = distances[top.z][top.y][top.x];
				todo.push_front(help);
			}
		}
		for(auto direction : directions) {
			if(distances[top.z][top.y + direction.y][top.x + direction.x] < 0 && board[top.z][top.y + direction.y][top.x + direction.x]) {
				distances[top.z][top.y + direction.y][top.x + direction.x] = distances[top.z][top.y][top.x] + 1;
				todo.push_back({top.z, top.y + direction.y, top.x + direction.x});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y >> z;
	for(int i = 1; i <= z; ++i) {
		for(int j = 1; j <= y; ++j) {
			for(int k = 1; k <= x; ++k) {
				char type;
				cin >> type;
				if(type == 'O')
					board[i][j][k] = 1;
			}
		}
	}

	cin >> m;
	for(int i = 0; i < m; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		b = y-b+1;
		if(c > d)
			swap(c, d);

		while(!board[c][b][a] && c <= d)
			++c;

		for(int j = c + 1; j <= d; ++j) {
			if(board[j][b][a]) {
				lifts[convert({j, b, a})].push_back(convert({c, b, a}));
				lifts[convert({c, b, a})].push_back(convert({j, b, a}));
			}
		}
	}

	int p, q, r;
	int i, j, k;
	cin >> p >> q >> r;
	cin >> i >> j >> k;
	q = y-q+1;
	j = y-j+1;

	bfs({r, q, p});

	cout << distances[k][j][i];
	return 0;
}