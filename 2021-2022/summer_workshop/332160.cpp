#include <bits/stdc++.h>
using namespace std;
queue <int> todo;
vector <int> graph[int(1e6) + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int distances[n + 1];
    for(int i = 0; i <=n; ++i)
        distances[i] = m + 1;
    distances[1] = 0;
    todo.push(1);
    while(!todo.empty()) {
        int top = todo.front();
        todo.pop();
        for(int branch = 0; branch < graph[top].size(); ++branch) {
            if(distances[graph[top][branch]] == m + 1) {
                distances[graph[top][branch]] = distances[top] + 1;
                todo.push(graph[top][branch]);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(distances[i] == m + 1)
            cout << -1 << "\n";
        else
            cout << distances[i] << "\n";
    }
}