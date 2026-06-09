#include <bits/stdc++.h>
#define ll long long
using namespace std;

stack <ll> operation;
ll n;

ll reduction(char type) {
	ll result = operation.top();
	operation.pop();
	if(type == '+')
		result = operation.top() + result;
	else if(type == '-')
		result = operation.top() - result;
	else if(type == '*')
		result = operation.top() * result;
	else
		result = operation.top() / result;
	operation.pop();
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(ll i = 0; i < n; ++i) {
		string type;
		cin >> type;
		if(type == "+" || type == "-" || type == "*" || type == "/")
			operation.push(reduction(type[0]));
		else
			operation.push(stoi(type));
	}
	cout << operation.top();
}