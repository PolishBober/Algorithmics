#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int c[n];
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    long long minc = c[n - 1], sum = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(minc > c[i]) minc = c[i];
        sum += minc;
    }
    cout << sum;
}