#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(1e6 + 7)
#define MAXZ int(1e5 + 7)

ll start[MAXN];

struct Edge {
	ll beg, end;
	ll fractions;
};
static bool operator < (const Edge &a, const Edge &b) {
	if((start[a.end] - start[a.beg]) / a.fractions == (start[b.end] - start[b.beg]) / b.fractions)
		return a.beg > b.beg;
	return (start[a.end] - start[a.beg]) / a.fractions < (start[b.end] - start[b.beg]) / b.fractions;
}


pair <ll, ll> input[MAXZ];
ll answer[MAXZ];

ll n, x, z;



void solv() {
	priority_queue <Edge> todo_sort;
	ll pointer = 0;

	for(ll i = 0; i < n - 1; ++i)
		todo_sort.push({i, i + 1, 2});

	queue <Edge> todo;


	ll k = 0;
	while(pointer < z) {
		Edge top;
		bool type = false;
		if(!todo.empty()) {
			if(!todo_sort.empty() && todo.front() < todo_sort.top())
				top = todo_sort.top();
			else {
				type = true;
				top = todo.front();
			}
		}
		else
			top = todo_sort.top();

		
		if(k + top.fractions / 2 >= input[pointer].first) {

			ll dist = input[pointer].first - k;
			ll sample = (start[top.end] - start[top.beg]) / top.fractions;
			ll distance = sample * (2 * (dist - 1) + 1);

			answer[input[pointer].second] = start[top.beg] + distance;

			++pointer;
		}

		if(input[pointer].first > k + top.fractions / 2) {

			todo.push({top.beg, top.end, top.fractions * 2});

			if(type)
				todo.pop();
			else
				todo_sort.pop();
			k += top.fractions / 2;
		}


	}

}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x >> z;
	for(ll i = 0; i < n; ++i) {
		cin >> start[i];
		start[i] *= (1 << 30);
	}
	for(ll i = 0; i < z; ++i) {
		cin >> input[i].first;
		input[i].second = i;
	}

	sort(input, input + z);


	solv();


	for(ll i = 0; i < z; ++i) {
		ll denominator = (1 << 30);
		ll nwd = gcd(denominator, answer[i]);
		denominator /= nwd;
		answer[i] /= nwd;
		cout << answer[i] << '/' << denominator << '\n';
	}

	return 0;
}