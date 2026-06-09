#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Block {
	int cost, size;
};
static bool operator < (Block a, Block b) {
	return a.cost > b.cost;
}

#define MAXN int(5e5) + 1
set <int> dock;
vector <Block> blocks;
int m, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 1; i <= MAXN + 1; ++i)
		dock.insert(i);

	cin >> m >> n;
	for(int i = 0; i < n; ++i) {
		int w, h;
		cin >> w >> h;
		blocks.push_back({w, h});
	}
	sort(blocks.begin(), blocks.end());

	ll answer = 0;
	for(auto block : blocks) {
		int index = *dock.lower_bound(block.size);
		if(index <= m) {
			dock.erase(index);
			answer += block.cost;
		}
	}
	cout << answer;
}