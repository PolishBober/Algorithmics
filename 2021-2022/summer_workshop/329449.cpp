#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long segments[n];
    for(int i = 0; i < n; ++i)
        cin >> segments[i];
    long long maxdelicious = -1e6, maxpref = -1e6, pref = 0;
    for(int i = 0; i < n; ++i) {
        pref += segments[i];
        if(pref > maxpref)
            maxpref = pref;
        if(pref < 0 || i == n - 1) {
            if(maxpref > maxdelicious)
                maxdelicious = maxpref;
            pref = 0;
        }
    }
    cout << maxdelicious;
}