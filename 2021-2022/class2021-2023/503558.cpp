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

bool bigger(string a, string b) {
	if(a.size() > b.size())
		return true;
	if(a.size() < b.size())
		return false;
	ll index = -1;
	while(a[++index] == b[index]) {}
	return a[index] > b[index];
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

void sub(string a, string b) {
	bool jump = 0;
	string answer;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(ll i = 0; i < a.size(); ++i) {
		ll sum = 10;
		if(i < a.size())
			sum += to_int(a[i]);
		if(i < b.size())
			sum -= to_int(b[i]);
		sum -= jump;
		jump = (sum < 10);
		answer += to_char(sum - 10 * (!jump));
	}
	while(answer.back() == '0' && answer.size() > 1)
		answer.pop_back();
	reverse(answer.begin(), answer.end());
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	bool positive1 = !(a[0] == '-'), positive2 = !(b[0] == '-');
	string number1, number2;
	if(positive1)
		number1 = a;
	else
		for(ll i = 1; i < a.size(); ++i)
			number1 += a[i];
	if(positive2)
		number2 = b;
	else
		for(ll i = 1; i < b.size(); ++i)
			number2 += b[i];
	if(positive1 ^ positive2) {
		if(bigger(number2, number1)) {
			swap(number1, number2);
			positive1 = positive2;
		}
		if(!positive1 && number1 != number2)
			cout << '-';
		sub(number1, number2);
	}
	else {
		if(!positive1)
			cout << '-';
		add(number1, number2);
	}
}