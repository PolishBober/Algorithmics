#include <iostream>
using namespace std;
const int maxn = 1e6;
int nlist[maxn][3];
long long pref[maxn + 2];

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 0; i < n; ++i) {
        cin >> nlist[i][0] >> nlist[i][1] >> nlist[i][2];
        pref[nlist[i][0]] += nlist[i][2];
        pref[nlist[i][1] + 1] -= nlist[i][2];
    }
    for(int i = 0; i < k; ++i) {
        pref[i + 1] += pref[i];
    }
    for(int i = 0; i < q; ++i) {
        int ask;
        cin >> ask;
        cout << pref[ask] << "\n";
    }
    return 0;
}