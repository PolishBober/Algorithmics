#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int exercises[n], ascending[n];
    for(int i = 0; i < n; ++i)
        cin >> exercises[i];
    int length = 1;
    for(int i = 0; i < n; ++i) {
        if(i > 0 && ascending[length - 1] < exercises[i])
            ascending[length++] = exercises[i];
        else {
            int a = 0, b = length;
            while(b - a > 1) {
                int between = (a + b) / 2;
                if(ascending[between - 1] >= exercises[i])
                    b = between;
                else
                    a = between;

            }
            ascending[a] = exercises[i];
        }
    }
    cout << length;
}