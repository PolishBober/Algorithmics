#include <bits/stdc++.h>
#define ll long long
using namespace std;

string a, b;

ll to_int(char letter) {
	return letter - '0';
}

char to_char(ll digit) {
	return digit + '0';
}

void add(string a, string b) {
	bool jump = 0;
	string answer;
	if(a.size() < b.size())
		swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(ll i = 0; i < a.size(); ++i) {
		ll sum = to_int(a[i]) + jump;
		if(i < b.size())
			sum += to_int(b[i]);
		jump = sum / 10;
		answer += to_char(sum - 10 * jump);
	}
	if(jump)
		answer += to_char(jump);
	reverse(answer.begin(), answer.end());
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	add(a, b);
}