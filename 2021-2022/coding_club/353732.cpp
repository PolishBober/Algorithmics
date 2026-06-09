#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long distances[n - 1], a = 0, b = 1;
    for(int i = 0; i < n - 1; ++i) {
        cin >> distances[i];
        a = max(a, distances[i]);
        b += distances[i];
    }
    while(a - b) {
        long long between = (a + b) / 2, distance = 0, days = 1;
        for(int i = 0; i < n - 1; ++i) {
            if(distance + distances[i] <= between)
                distance += distances[i];
            else {
                ++days;
                distance = distances[i];
            }
        }
        if(days <= k)
            b = between;
        else
            a = between + 1;
    }
    cout << a;
}