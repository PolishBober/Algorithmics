#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline void readUI(ll *n) //tylko dodatnie
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

#define MAXN int(2e6) + 1

pair <ll, ll> liders[MAXN];
pair <ll, ll> commands[MAXN];
ll n, m, k;

ll Find(ll vertex) {
	if(liders[vertex].first == vertex)
		return vertex;
	liders[vertex].first = Find(liders[vertex].first);
	return liders[vertex].first;
}

void Union(ll vertex1, ll vertex2) {
	vertex1 = Find(vertex1);
	vertex2 = Find(vertex2);
	if(liders[vertex1].second < liders[vertex2].second)
		swap(vertex1, vertex2);
	liders[vertex1].second += liders[vertex2].second;
	liders[vertex2].first = vertex1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	readUI(&n);
	readUI(&m);
	readUI(&k);
	for(ll i = 1; i <= n; ++i)
		liders[i] = {i, 1};
	for(ll i = 0; i < m; ++i) {
		ll a, b;
		readUI(&a);
		readUI(&b);
		commands[i] = {a, b};
	}

	ll answer = m + 1;
	for(ll i = m - 1; i >= 0; --i) {
		if(Find(commands[i].first) != Find(commands[i].second)) {
			Union(commands[i].first, commands[i].second);
			--n;
		}
		if(n == k)
			answer = i + 1;
		if(n < k)
			break;
	}
	printf("%d", answer);
	return 0;
}