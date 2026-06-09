#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
	ll beg, end, lider;
};
static bool operator < (Description a, Description b) {
	return a.beg < b.beg;
}

const ll maxn = 1e6;
const ll maxm = 1e6;
ll liders[3 * maxn];
ll n, m, p;

vector <Description> intervals[maxn + 1];
vector <Description> white[maxn + 1];
vector <Description> black[maxn + 1];
ll lider;

bool scaner(ll line) {
	if(intervals[line].empty()) {
		white[line].push_back({1, n, ++lider});
		return 0;
	}
	sort(intervals[line].begin(), intervals[line].end());
	black[line].push_back({intervals[line][0].beg, intervals[line][0].end, ++lider});
	for(auto interval : intervals[line]) {
		if(black[line].back().beg <= interval.beg && interval.beg <= black[line].back().end + 1)
			black[line].back().end = max(black[line].back().end, interval.end);
		else
			black[line].push_back({interval.beg, interval.end, ++lider});
	}

	if(black[line][0].beg > 1)
		white[line].push_back({1, black[line][0].beg - 1, ++lider});
	for(ll i = 1; i < black[line].size(); ++i)
		white[line].push_back({black[line][i - 1].end + 1, black[line][i].beg - 1, ++lider});
	if(black[line].back().end < n)
		white[line].push_back({black[line].back().end + 1, n, ++lider});
	return 1;
}

ll Find(ll vertex) {
	if(liders[vertex] == vertex)
		return vertex;
	liders[vertex] = Find(liders[vertex]);
	return liders[vertex];
}

void Union(ll vertex1, ll vertex2) {
	liders[Find(vertex2)] = Find(vertex1);
}

bool comparison(Description interval1, Description interval2) {
	return interval1.beg - 1 <= interval2.beg && interval1.end + 1 >= interval2.beg || interval1.beg - 1 <= interval2.end && interval1.end + 1 >= interval2.end || interval1.beg + 1 >= interval2.beg && interval1.beg - 1 <= interval2.end || interval1.end + 1 >= interval2.beg && interval1.end - 1 <= interval2.end;
}

void bridge(vector <Description> &line1, vector <Description> &line2) {
	ll index1 = 0, index2 = 0;
	while(index1 < line1.size() && index2 < line2.size()) {
		if(comparison(line1[index1], line2[index2]))
			Union(line1[index1].lider, line2[index2].lider);
		if(line1[index1].end > line2[index2].end)
			++index2;
		else
			++index1;
	}
}

ll binsearch(vector <Description> &line, ll x) {
	ll beg = 0, end = line.size();
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(line[mid].beg <= x)
			beg = mid;
		else
			end = mid;
	}
	if(!line.size() || x < line[beg].beg || line[beg].end < x)
		return -1;
	return beg;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(ll i = 0; i < 2 * maxn + 1; ++i)
		liders[i] = i;

	cin >> n >> m >> p;

	for(ll i = 0; i < m; ++i) {
		ll a, b, c;
		cin >> a >> b >> c;
		intervals[a].push_back({b, c});
	}

	for(ll i = 1; i <= n; ++i) {
		scaner(i);
		if(i > 1) {
			bridge(white[i], white[i - 1]);
			bridge(black[i], black[i - 1]);
		}
	}

	for(ll i = 0; i < p; ++i) {
		ll y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		ll index1 = binsearch(white[y1], x1);
		ll index2 = binsearch(white[y2], x2);
		if(index1 >= 0 && index2 >= 0 && Find(white[y1][index1].lider) == Find(white[y2][index2].lider)) {
			cout << "TAK\n";
			continue;
		}

		index1 = binsearch(black[y1], x1);
		index2 = binsearch(black[y2], x2);
		if(index1 >= 0 && index2 >= 0 && Find(black[y1][index1].lider) == Find(black[y2][index2].lider))
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
	return 0;
}