#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN int(5e5 + 7)
#define BASE int(1 << 19)

ll atree[2 * BASE];
ll btree[2 * BASE];

void set_point(ll vertex, ll value, ll (&tree)[2 * BASE]) {
	vertex += BASE;
	tree[vertex] += value;
	vertex /= 2;
	while(vertex) {
		tree[vertex] += value;
		vertex /= 2;
	}
}

ll query_interval(ll beg, ll end, ll (&tree)[2 * BASE]) {
	beg += BASE;
	end += BASE;
	ll answer = 0;
	while(beg <= end) {
		if(beg % 2)
			answer += tree[beg];
		if(!(end % 2))
			answer += tree[end];
		beg = (beg + 1) / 2;
		end = (end - 1) / 2;
	}
	return answer;
}



vector <ll> graph[MAXN];

set <ll> a;
set <ll> b;
ll acount0[MAXN];
ll acount1[MAXN];
ll bcount0[MAXN];
ll bcount1[MAXN];
ll n, q;


ll capacity[MAXN];
bool visited[MAXN];
void dfs(ll vertex) {
	visited[vertex] = true;
	capacity[vertex] = 1;
	for(auto edge : graph[vertex]) {
		if(!visited[edge]) {
			dfs(edge);
			capacity[vertex] += capacity[edge];
		}
	}
}

ll distances[MAXN];
bool team[MAXN];
void dfs_distances(ll vertex) {
	for(auto edge : graph[vertex]) {
		if(distances[edge] == -1) {
			distances[edge] = distances[vertex] + 1;
			team[edge] = team[vertex];
			dfs_distances(edge);
		}
	}
}

vector <ll> centroid;
void centr(ll vertex) {

	while(1) {
		for(auto edge : graph[vertex]) {
			if(capacity[edge] > capacity[vertex]) {
				if(n - capacity[vertex] > n / 2) {
					vertex = edge;
					goto next;
				}
				else if(n - capacity[vertex] == n / 2 && !(n % 2))
					centroid.push_back(edge);
			}
			else if(capacity[edge] < capacity[vertex]) {
				if(capacity[edge] > n / 2) {
					vertex = edge;
					goto next;
				}
				else if(capacity[edge] == n / 2 && !(n % 2))
					centroid.push_back(edge);
			}
		}
		centroid.push_back(vertex);
		break;
		next:;
	}
}


ll solv() {
	ll answer = 0;

	for(auto first : a) {
		answer += query_interval(distances[first] + 1, n, btree);
		if(team[first])
			answer += bcount1[distances[first]];
		else
			answer += bcount0[distances[first]];
		if(b.find(first) != b.end())
			--answer;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n - 1; ++i) {
		ll a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);
	centr(1);
	for(ll i = 1; i <= n; ++i)
		distances[i] = -1;
	for(auto c : centroid)
		distances[c] = 0;
	team[centroid[0]] = true;
	for(auto c : centroid)
		dfs_distances(c);

	ll sa, sb;
	cin >> sa >> sb >> q;
	for(ll i = 0; i < sa; ++i) {
		ll z;
		cin >> z;
		if(a.find(z) != a.end())
			continue;
		a.insert(z);
		set_point(distances[z], 1, atree);
		if(team[z])
			++acount1[distances[z]];
		else
			++acount0[distances[z]];
	}
	for(ll i = 0; i < sb; ++i) {
		ll z;
		cin >> z;
		if(b.find(z) != b.end())
			continue;
		b.insert(z);
		set_point(distances[z], 1, btree);
		if(team[z])
			++bcount1[distances[z]];
		else
			++bcount0[distances[z]];
	}

	ll answer = solv();
	cout << answer << '\n';

	for(ll i = 0; i < q; ++i) {
		char type1, type2;
		ll z;
		cin >> type1 >> type2 >> z;
		if(type1 == 'A') {
			ll sign = -1;
			if(type2 == '+') {
				a.insert(z);
				sign = 1;
			}
			else
				a.erase(z);

			set_point(distances[z], sign, atree);
			if(team[z])
				acount1[distances[z]] += sign;
			else
				acount0[distances[z]] += sign;

			answer += query_interval(distances[z] + 1, n, btree) * sign;
			if(team[z])
				answer += bcount1[distances[z]] * sign;
			else
				answer += bcount0[distances[z]] * sign;
			if(b.find(z) != b.end())
				answer -= sign;
		}
		else {
			ll sign = -1;
			if(type2 == '+') {
				b.insert(z);
				sign = 1;
			}
			else
				b.erase(z);

			set_point(distances[z], sign, btree);
			if(team[z])
				bcount1[distances[z]] += sign;
			else
				bcount0[distances[z]] += sign;

			answer += query_interval(0, distances[z] - 1, atree) * sign;
			if(team[z])
				answer += acount1[distances[z]] * sign;
			else
				answer += acount0[distances[z]] * sign;
			if(a.find(z) != a.end())
				answer -= sign;
		}
		cout << answer << '\n';
	}

	return 0;
}