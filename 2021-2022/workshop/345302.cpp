#include <bits/stdc++.h>
using namespace std;

void binsearch(int days, int* pref, int size_) {
    int a = 0, b = size_;
    while(b - a > 0) {
        int between = (a + b + 1) / 2;
        if(days > pref[between])
            a = between;
        else
            b = between-1;
    }
    cout << days - pref[a] << " " << a + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int amonths[a], bmonths[b], apref[a + 1], bpref[b + 1];
    apref[0] = 0;
    bpref[0] = 0;
    for(int i = 0; i < a; ++i) {
        cin >> amonths[i];
        apref[i + 1] = apref[i] + amonths[i];
    }
    for(int i = 0; i < b; ++i) {
        cin >> bmonths[i];
        bpref[i + 1] = bpref[i] + bmonths[i];
    }
    int z;
    cin >> z;
    for(int i = 0; i < z; ++i) {
        int d, m, days;
        char c;
        cin >> d >> m >> c;
        if(c == 'A') {
            days = apref[m-1] + d;
            binsearch(days, bpref, b) ;
        }
        else {
            days = bpref[m-1] + d;
            binsearch(days, apref, a);
        }
    }
}