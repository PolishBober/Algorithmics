#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    --n;
    --m;
    pair <ll, bool> tab[m + n];
    ll breaks[2] = {1, 1};
    for(ll i = 0; i < n; ++i) {
        cin >> tab[i].first;
        tab[i].second = 0;
    }
    for(ll i = n; i < m + n; ++i) {
        cin >> tab[i].first;
        tab[i].second = 1;
    }
    sort(tab, tab + n + m);
    ll answer = 0;
    for(ll i = m + n - 1; i >= 0; --i) {
        answer += tab[i].first * breaks[!tab[i].second];
        ++breaks[tab[i].second];
    }
    cout << answer << '\n';
}