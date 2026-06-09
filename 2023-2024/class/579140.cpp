#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll k, n;
string word;
ll letters[256];

void gasiennica() {
	ll answer = 0;
	ll beg = -1, end = -1;
	ll types = 0;
	while(beg + 1 < n) {
		++beg;
		++letters[word[beg]];
		if(letters[word[beg]] == 1)
			++types;
		while(end + 1 < beg && types > k) {
			++end;
			--letters[word[end]];
			if(!letters[word[end]])
				--types;
		}
		answer = max(answer, beg - end);
	}
	cout << answer << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	cin.ignore();
	getline(cin, word);
	n = word.size();

	gasiennica();

	return 0;
}