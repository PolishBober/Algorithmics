#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(8e6) + 1

ll presuf[MAXN];
ll help[MAXN];
string word = " ", pattern = " ";

void kmp() {
	ll j = 0;
	for(ll i = 2; i < pattern.size(); ++i) {
		while(j && pattern[j + 1] != pattern[i])
			j = presuf[j];
		if(pattern[j + 1] == pattern[i])
			++j;
		presuf[i] = j;
	}

	vector <ll> answer;
	j = 0;
	for(ll i = 1; i < word.size(); ++i) {
		while(j && pattern[j + 1] != word[i])
			j = presuf[j];
		if(pattern[j + 1] == word[i])
			++j;
		help[i] = j;

		if(j + 1 == pattern.size())
			answer.push_back(i - pattern.size() + 2);
	}

	for(auto a : answer)
		cout << a << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	string help;
	cin >> help;
	pattern += help;
	cin >> help;
	word += help;

	kmp();
}