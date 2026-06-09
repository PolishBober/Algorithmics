#include <bits/stdc++.h>
using namespace std;
int graf[int(3e4) + 1];
int tables = 0;

void dfs(int top) {
    if(graf[top]) {
        int help = graf[top];
        graf[top] = 0;
        dfs(help);
    }
    else
        tables += 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> graf[i];
    }
    for(int i = 1; i <= n; ++i)
        if(graf[i])
            dfs(i);
    cout << tables;
}