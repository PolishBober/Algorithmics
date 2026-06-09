#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 mt;
ll seeds[5] = {1091, 1310, 1172, 1023, 1130};
pair <ll, ll> tests[5] = {{1,15}, {20, 100}, {150, 250}, {1000, 2000}, {500000, 1000000}};

ll draw(ll a, ll b){
	return mt()%(b-a+1)+a;
}

int main(){
	ll test;
	cin>>test;
	mt.seed(seeds[test]);
	ll n = draw(tests[test].first, tests[test].second);
	cout << n << '\n';
	for(ll i = 0; i < n - 1; ++i)
		cout << draw(1, n) << ' ' << draw(1, n) << '\n';
}