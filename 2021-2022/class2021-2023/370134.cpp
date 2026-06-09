#include <bits/stdc++.h>
using namespace std;

bool comparison(pair <int, int> a, pair <int, int> b) {
    if((double) a.first / (1<<a.second) == (double) b.first / (1<<b.second))
        return a.first < b.first;
    return (double) a.first / (1<<a.second) < (double) b.first / (1<<b.second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair <int, int> measurements[n];
    for(int i = 0; i < n; ++i)
        cin >> measurements[i].first >> measurements[i].second;
    sort(measurements, measurements + n, comparison);
    for(int i = 0; i < n; ++i)
        cout << measurements[i].first << " " << measurements[i].second << "\n";
}