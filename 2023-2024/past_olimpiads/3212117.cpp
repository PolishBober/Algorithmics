#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5 + 7)


ll input[MAXN][2];

ll n, s;

bool moves[MAXN];


ll repetitions[MAXN];
ll stars[MAXN];
void solv() {

	for(ll i = n - 3; i >= 0; --i)
		if(moves[i] == moves[i + 1])
			repetitions[i] = repetitions[i + 1] + 1;
	
	bool help = 0;
	for(ll i = 1; i <= n; ++i) {
		if(i == s) {
			help = 1;
			continue;
		}
		stars[i - help] = i;
	}


	// for(ll i = 0; i < n; ++i)
	// 	cout << repetitions[i] << ' ';
	// cout << '\n';
	// for(ll i = 1; i < n; ++i)
	// 	cout << stars[i] << ' ';
	// cout << '\n';



	ll beg = 1;
	ll end = n - 1;

	vector <ll> answer = {s};

	ll index = 0;
	while(index < n - 1) {

		if(moves[index]) {
			for(ll j = repetitions[index]; j >= 0; --j)
				answer.push_back(stars[end - j]);

			end -= repetitions[index] + 1;
		}
		else {
			for(ll j = repetitions[index]; j >= 0; --j)
				answer.push_back(stars[beg + j]);

			beg += repetitions[index] + 1;
		}
		index += repetitions[index] + 1;

	}


	ll sum = 0;
	for(ll i = 0; i < n - 1; ++i)
		sum += input[i][moves[i]];

	cout << sum << '\n';
	for(auto a : answer)
		cout << a << ' ';
	cout << '\n';
	
}


void prep() {

	for(ll i = 0; i < n - 1; ++i) {
		if(input[i][0] < input[i][1])
			moves[i] = 0;
		else
			moves[i] = 1;
	}

	if(input[0][0] == input[0][1])
		return;


	if(s == 1) {
		moves[0] = 1;
		return;
	}
	if(s == n) {
		moves[0] = 0;
		return;
	}


	bool side = 0;
	ll wall = s - 1;
	if(input[0][0] > input[0][1]) {
		side = 1;
		wall = n - s;
	}


	ll minimum = 0;
	for(ll i = 1; i < wall + 1; ++i) {
		if(input[i][side] >= input[i][!side])
			return;

		if(input[minimum][!side] - input[minimum][side] > input[i][!side] - input[i][side])
			minimum = i;
	}

	moves[minimum] = !side;

}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for(ll i = 0; i < n - 1; ++i)
		cin >> input[i][0] >> input[i][1];


	prep();

	solv();

	return 0;
}