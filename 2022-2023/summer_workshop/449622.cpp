#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int backpack[k + 1];
    for(int i = 0; i < k + 1; ++i)
        backpack[i] = 0;
    for(int i = 0; i < n; ++i) {
        int c, s;
        cin >> c >> s;
        for(int j = k; j >= 0; --j) {
            if(backpack[j] || !j)
                if(j + c <= k)
                    backpack[j + c] = max(backpack[j + c], backpack[j] + s);
        }
    }
    int answer = 0;
    for(int i = k; i > 0; --i) {
        answer = max(answer, backpack[i]);
    }
    cout << answer;
}