#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 2e5;
pair <double, ll> tab[maxn];
ll n, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> v;
    for(ll i = 0; i < n; ++i)
        cin >> tab[i].second;
    for(ll i = 0; i < n; ++i) {
        cin >> tab[i].first;
        tab[i].first /= tab[i].second;
    }
    sort(tab, tab + n);
    double answer = 0;
    for(ll i = n - 1; i >= 0; --i) {
        if(v - tab[i].second < 0) {
            answer += v * tab[i].first;
            break;
        }
        else {
            answer += tab[i].first * tab[i].second;
            v -= tab[i].second;
            if(!v)
                break;
        }
    }
    cout << fixed << setprecision(7) << answer << '\n';
}