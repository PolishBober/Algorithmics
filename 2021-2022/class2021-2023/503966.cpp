#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
string numb;

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

void simplify(string &x, ll commaIndex) {
	while(x.back() == '0' && x.size() > commaIndex)
		x.pop_back();
	string help;
	ll size = x.size();
	for(ll i = 0; i < size; ++i) {
		if(help.size() == commaIndex) {
			help += ',';
			--i;
		}
		else
			help += x[i];
	}
	x = help;
	size = x.size();
	help.clear();
	for(ll i = 0; i < size; ++i)
		if(!(x[i] == '0' && !help.size() && i + 1 < commaIndex))
			help += x[i];
	x = help;
}

string add(string a, string b, ll commaIndex) {
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
	if(jump) {
		answer += to_char(jump);
		++commaIndex;
	}
	reverse(answer.begin(), answer.end());
	simplify(answer, commaIndex);
	return answer;
}

string sub(string a, string b, ll commaIndex) {
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
	reverse(answer.begin(), answer.end());
	simplify(answer, commaIndex);
	return answer;
}

ll standardize(string &a, string &b) {
	if(find(a.begin(), a.end(), ',') == a.end())
		a += ',';
	if(find(b.begin(), b.end(), ',') == b.end())
		b += ',';
	ll index1 = distance(a.begin(), find(a.begin(), a.end(), ','));
	ll index2 = distance(b.begin(), find(b.begin(), b.end(), ','));
	ll help = max(a.size() - index1, b.size() - index2) - (a.size() - index1);
	for(ll i = 0; i < help; ++i)
		a += '0';
	help = max(a.size() - index1, b.size() - index2) - (b.size() - index2);
	for(ll i = 0; i < help; ++i)
		b += '0';
	string number1, number2;
	for(ll i = 0; i < a.size(); ++i)
		if(a[i] != ',')
			number1 += a[i];
	for(ll i = 0; i < b.size(); ++i)
		if(b[i] != ',')
			number2 += b[i];
	a = number1;
	b = number2;
	return max(index1, index2);
}

string floatAdd(string a, string b) {
	bool positive1 = !(a[0] == '-'), positive2 = !(b[0] == '-');
	string number1, number2;
	if(positive1) {
		if(a[0] == '+')
			for(ll i = 1; i < a.size(); ++i)
				number1 += a[i];
		else
			number1 = a;
	}
	else
		for(ll i = 1; i < a.size(); ++i)
			number1 += a[i];
	if(positive2) {
		if(b[0] == '+')
			for(ll i = 1; i < b.size(); ++i)
				number2 += b[i];
		else
			number2 = b;
	}
	else
		for(ll i = 1; i < b.size(); ++i)
			number2 += b[i];
	ll commaIndex = standardize(number1, number2);
	string answer;
	if(positive1 ^ positive2) {
		if(bigger(number2, number1)) {
			swap(number1, number2);
			positive1 = positive2;
		}
		if(!positive1 && number1 != number2)
			answer += '-';
		answer += sub(number1, number2, commaIndex);
	}
	else {
		if(!positive1)
			answer =+ '-';
		answer += add(number1, number2, commaIndex);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	string answer = "0";
	cin >> n;
	for(ll i = 0; i < n; ++i) {
		cin >> numb;
		answer = floatAdd(answer, numb);
	}
	cout << answer;
	return 0;	
}