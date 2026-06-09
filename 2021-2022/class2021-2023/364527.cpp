#include <bits/stdc++.h>
using namespace std;

int NWD(int a, int b) {
    if(a > b)
        swap(a, b);
    while(a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T, K, N, x1, y1, x2, y2;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> K >> N >> x1 >> y1 >> x2 >> y2;
        pair <long long, long long> positions[4] = {{x1, y1}, {x1 + K, y1 + N}, {x1 + N, y1 + K}, {x1 + K + N, y1 + K + N}};
        int nwd = NWD(2 * K, 2 * N);
        bool can = false;
        for(int j = 0; j < 4; ++j)
            if(!((x2 - positions[j].first) % nwd) && !((y2 - positions[j].second) % nwd))
                can = true;
        if(can)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}