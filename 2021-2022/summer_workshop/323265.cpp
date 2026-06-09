#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int s[n + 1], c[m];
    s[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; ++i) {
        if(s[i] < s[i - 1])
            s[i] = s[i - 1];
    }
    for(int i = 0; i < m; ++i) {
        int a = 0, b = n + 1;
        while(b - a > 1) {
            int between = (a + b) / 2;
            if(s[between] >= c[i])
                b = between;
            else
                a = between;
        }
        if(i != 0)
            cout << " ";
        cout << a;
    }
}