#include <bits/stdc++.h>
using namespace std;
bool available[int(1e5) + 1];
vector <int> graf[int(1e6) + 1];

void dfs(int top) {
    available[top] = true;
    for(int i : graf[top]) {
        if(!available[i])
            dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        if(available[i])
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}