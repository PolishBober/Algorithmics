#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Coordinates {
	ll y, x;
	bool checked;
};

const ll maxn = 2e3;
Coordinates positions[maxn];
ll lowest[maxn];
ll n;

double pitagoras(Coordinates position1, Coordinates position2) {
	return sqrt(pow(position1.y - position2.y, 2) + pow(position1.x - position2.x, 2));
}

void mst_prim2(ll range, ll vertex) {
	for(auto & l : lowest)
		l = -1;
	double answer = 0;
	positions[vertex].checked = true;
	for(ll i = 0; i < range - 1; ++i) {
		for(ll edge = 0; edge < range; ++edge)
			if(!positions[edge].checked && (lowest[edge] < 0 || pitagoras(positions[edge], positions[lowest[edge]]) > pitagoras(positions[edge], positions[vertex])))
				lowest[edge] = vertex;
		for(ll edge = 0; edge < range; ++edge)
			if(!positions[edge].checked && (positions[vertex].checked || pitagoras(positions[vertex], positions[lowest[vertex]]) > pitagoras(positions[edge], positions[lowest[edge]])))
				vertex = edge;
		positions[vertex].checked = true;
		answer += pitagoras(positions[vertex], positions[lowest[vertex]]);
	}
	cout << setprecision(4) << fixed << answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(ll i = 0; i < n; ++i) {
		ll y, x;
		cin >> y >> x;
		positions[i] = {y, x};
	}

	mst_prim2(n, 0);
}