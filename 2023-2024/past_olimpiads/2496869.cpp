#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll integer(char digit) {
	return digit - 48;
}

string sum(string s1, string s2) {
	if(s1.size() < s2.size())
		swap(s1, s2);
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	string answer;
	ll jump = 0;
	for(ll i = 0; i < s1.size(); ++i) {
		ll digit = jump + integer(s1[i]);
		if(i < s2.size())
			digit += integer(s2[i]);
		jump = digit / 10;
		answer += to_string(digit % 10);
	}
	if(jump)
		answer += to_string(jump);
	reverse(answer.begin(), answer.end());
	return answer;
}

string conversion(string number) {
	string answer;
	for(auto character : number)
		answer = sum(to_string(integer(character) * integer(character)), answer);
	return answer;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	cin >> t;
	for(ll i = 0; i < t; ++i) {
		string number;
		cin >> number;
		cout << number << ' ';
		while(!(number.size() == 1 && (integer(number[0]) == 4 || integer(number[0]) == 1))) {
		// for(ll i = 0; i < 5; ++i) {
			number = conversion(number);
			cout << number << ' ';
		}
		cout << '\n';
	}
}