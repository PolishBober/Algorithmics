#include <iostream>
using namespace std;
const int maxn = 1e6 + 1;
int nlist[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> nlist[i + 1];
        nlist[i + 1] += nlist[i];
    }
    for(int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << nlist[b] - nlist[a - 1] << "\n";
    }
}