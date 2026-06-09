#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m = n;
    while(m / 10)
        m /= 10;
    cout << (n % 10) * m;
}