#include <bits/stdc++.h>
using namespace std;

#define MAXN int(1e3 + 2)

int pref[MAXN][MAXN];
int n, m, k;
int answer;


void gasiennica(int i, int j) {
	int end = 1;
	for(int beg = 1; beg <= n; ++beg) {
		while(end <= n && k < pref[beg][j] - pref[beg][i - 1] - pref[end - 1][j] + pref[end - 1][i - 1])
			++end;
		answer = max(answer, (beg - end + 1) * (j - i + 1));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		string help;
		cin >> help;
		for(int j = 1; j <= m; ++j)
			pref[i][j] = int(help[j - 1] - '0') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
	}

	for(int i = 1; i <= m; ++i) {
		for(int j = i; j <= m; ++j) {
			gasiennica(i, j);			
		}
	}

	cout << answer << '\n';

	return 0;
}