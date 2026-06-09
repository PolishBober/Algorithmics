#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string input;
    cin >> input;
    int lollipop[n];
    for(int i = 0; i < n; ++i)
        lollipop[i] = 1 + (input[i] == 'T');
    for(int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int sum = 0, a = 0, b = 0;
        for(int j = 0; j < n; ++j) {
            b = j;
            sum += lollipop[j];
            while(sum > k) {
                sum -= lollipop[a];
                a++;
            }
            //cout << sum << " " << a << " " << b << "\n";
            if(sum == k)
                break;
        }
        if(sum == k)
            cout << a + 1 << " " << b + 1 << "\n";
        else
            cout << "NIE\n";
    }
}