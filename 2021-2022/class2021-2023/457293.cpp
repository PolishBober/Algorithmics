#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 2e5;
pair <ll, ll> intervals[maxn];
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n ; ++i)
        cin >> intervals[i].second >> intervals[i].first;
    sort(intervals, intervals + n);
    ll last = 0, answer = 0;
    for(ll i = 0; i < n; ++i) {
        if(last <= intervals[i].second) {
            last = intervals[i].first;
            ++answer;
        }
    }
    cout << answer << '\n';
}