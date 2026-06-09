#include <bits/stdc++.h>
using namespace std;

queue <int> lowerBound;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	multiset <int> bar;
	int value = -1e9, answer = 0;
	for(int beg = 0; beg < n; ++beg) {
		int down, up;
		cin >> down >> up;
		lowerBound.push(down);
		bar.insert(-down);
		value = max(value, down);
		while(value > up) {
			bar.erase(bar.find(-lowerBound.front()));
			value = -*bar.lower_bound(-1e9);
			lowerBound.pop();
		}
		answer = max(answer, int(lowerBound.size()));
	}
	cout << answer;

	return 0;
}