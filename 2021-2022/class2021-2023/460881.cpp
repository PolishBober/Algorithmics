#include <bits/stdc++.h>
using namespace std;

int nwd(int a, int b) {
    while(min(a, b)) {
        int help = a;
        a = max(a, b) % min(a, b);
        b = min(help, b);
    }
    return max(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int numbers[n];
    for(int i = 0; i < n; ++i)
        cin >> numbers[i];
    int answer = numbers[0];
    for(int i = 1; i < n; ++i)
        answer = nwd(answer, numbers[i]);
    cout << answer;
}