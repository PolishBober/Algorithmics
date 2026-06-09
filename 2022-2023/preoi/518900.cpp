#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sum;
string word;

int stoi(char letter) {
	return letter - 48;
}

char to_char(int number) {
	return number + 48;
}

void prep() {
	for(auto letter : word)
		sum += stoi(letter);
}

void solv() {
	string answer;
	int jump = 0;
	for(int i = 0; i < word.size(); ++i) {
		answer += to_char((jump + sum) % 10);
		jump = (jump + sum) / 10;
	}
	while(jump) {
		answer += to_char(jump % 10);
		jump /= 10;
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> word;

	prep();
	solv();

	return 0;
}