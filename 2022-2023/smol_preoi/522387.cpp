#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6) + 1

struct Description {
	ll sum;
	bool index, full;
};
static bool operator < (const Description &a, const Description &b) {
	return a.sum < b.sum;
}

int input[MAXN][2];
Description dp[MAXN][4];
int n;

void solv() {
	dp[0][0] = {0, 0, false};
	dp[0][1] = {0, 0, true};
	dp[0][2] = {0, 1, false};
	dp[0][3] = {0, 1, true};
	for(int i = 1; i <= n; ++i) {
		for(auto &now : dp[i])
			now.sum = LLONG_MIN;
		for(auto back : dp[i - 1]) {
			if(back.full)
				dp[i][2 * (!back.index) + back.full] = max(dp[i][2 * (!back.index) + back.full], {back.sum + input[i][!back.index], !back.index, false});
			else {
				dp[i][2 * back.index + back.full] = max(dp[i][2 * back.index + back.full], {back.sum + input[i][back.index], back.index, true});
				dp[i][2 * (!back.index) + !back.full] = max(dp[i][2 * (!back.index) + !back.full], {back.sum + input[i][!back.index], !back.index, false});
			}
		}
	}

	ll answer = LLONG_MIN;
	for(auto back : dp[n])
		answer = max(answer, back.sum);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> input[i][0];
	for(int i = 1; i <= n; ++i)
		cin >> input[i][1];

	solv();

	return 0;
}