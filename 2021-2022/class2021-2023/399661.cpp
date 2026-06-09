#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int size[n];
    for(int i = 0; i < n; ++i)
        cin >> size[i];
    sort(size, size + n);
    int b = 2, maximum = 0;
    for(int e = 0; e < n - 2; ++e) {
        while(b < n && size[e] + size[e + 1] > size[b]) {
            ++b;
        }
        maximum = max(maximum, b - e);
    }
    cout << maximum;
}