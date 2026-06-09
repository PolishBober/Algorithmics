#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline void readUI(int *n) //tylko dodatnie
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

struct Interval {
	int beg, end, x, y;
};
static bool operator < (const Interval &a, const Interval &b) {
	if(a.beg == b.beg) {
		if(a.end == b.end)
			return a.y < b.y;
		return a.end < b.end;
	}
	return a.beg < b.beg;
}
bool comparator(const Interval &a, const Interval &b) {
	if(a.x) {
		if(b.x)
			return a.x < b.x;
		return a.x < b.beg;
	}
	if(b.x)
		return a.beg < b.x;
	return a.beg < b.beg;
}

vector <Interval> intervals;
int xMin, xMax, yMin, yMax;
int n, m;

void write(Interval interval) {
	cout << interval.beg << ' ' << interval.end << ' ' << interval.x << ' ' << interval.y << '\n';
}

bool condition(int mid) {
	set <Interval> horizontal;
	for(auto interval : intervals) {
		// write(interval);
		if(interval.end - interval.beg + 1 > 2 * mid) {
			if(interval.y && !(xMax <= interval.beg || interval.end <= xMin))
				horizontal.insert({interval.beg + mid, interval.end - mid, 0, interval.y});
			else if(!(yMax <= interval.beg || interval.end <= yMin)) {
				for(auto help = horizontal.begin(); help != horizontal.end(); ) {
					if((*help).beg > interval.x)
						break;
					if((*help).end < interval.x)
						help = horizontal.erase(help);
					else {
						if(interval.beg + mid <= (*help).y && (*help).y <= interval.end - mid)
							return true;
						++help;
					}
				}
			}
		}
	}
	return false;
}

void binsearch() {
	int beg = 0, end = 5e8;
	while(end - beg > 1) {
		int mid = (beg + end) / 2;
		if(condition(mid))
			beg = mid;
		else
			end = mid;
	}
	printf("%d", beg);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	readUI(&n);
	readUI(&m);
	// cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		int x1, x2, y;
		readUI(&x1);
		readUI(&x2);
		readUI(&y);
		yMin = min(yMin, y);
		yMax = max(yMax, y);
		// cin >> x1 >> x2 >> y;
		intervals.push_back({x1, x2, 0, y});
	}
	for(int i = 0; i < m; ++i) {
		int y1, y2, x;
		readUI(&y1);
		readUI(&y2);
		readUI(&x);
		xMin = min(xMin, x);
		xMax = max(xMax, x);
		// cin >> y1 >> y2 >> x;
		intervals.push_back({y1, y2, x});
	}

	sort(intervals.begin(), intervals.end(), comparator);

	binsearch();

	return 0;
}