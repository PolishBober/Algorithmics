#include <bits/stdc++.h>
#include "libbin.h"
#define ll long long
using namespace std;


bool szukaj(int n, function<long long(int)> const& A, long long x) {
	ll beg = 1, end = n + 1;
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(A(beg) >= A(mid))
			beg = mid;
		else
			end = mid;
	}
	ll range = beg;

	beg = 0, end = n;
	while(end - beg > 1) {
		ll mid = (beg + end) / 2;
		if(A((mid + range) % n + 1) >= x)
			beg = mid;
		else
			end = mid;
	}
	return A((beg + range) % n + 1) == x;
}