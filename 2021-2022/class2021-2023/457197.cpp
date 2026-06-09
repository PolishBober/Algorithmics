#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, h;
    cin >> n >> m;
    long long result = 0, last = -1;
    for(int i = 0; i < n; ++i) {
        cin >> h;
        if(h >= m) {
            result += (i - last) * (n - i);
            last = i;
        }
    }
    cout << result;
}