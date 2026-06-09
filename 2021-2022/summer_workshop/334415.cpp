#include <bits/stdc++.h>
using namespace std;
queue <int> todo;
vector <int> graph[int(1e5) + 1];
int checked[int(1e5) + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int positions[k];
    for(int i = 0; i < k; ++i) {
        cin >> positions[i];
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    double distances[n + 1];
    for(int j = 0; j <=n; ++j)
        distances[j] = m + 1;
    for(int i = 0; i < k; ++i) {
        distances[positions[i]] = 0;
        checked[positions[i]] = i + 1;
        todo.push(positions[i]);
    }
    while(!todo.empty()) {
        int top = todo.front();
        todo.pop();
        for(int branch = 0; branch < graph[top].size(); ++branch) {
            if(distances[graph[top][branch]] == m + 1 && !checked[graph[top][branch]]) {
                distances[graph[top][branch]] = distances[top] + 1;
                checked[graph[top][branch]] = checked[top];
                todo.push(graph[top][branch]);
            }
            else if (checked[graph[top][branch]] != checked[top]) {
                cout << setprecision(1) << fixed << (distances[top] + distances[graph[top][branch]] + 1) / 2 << "\n";
                return 0;
            }

        }
    }
    cout << setprecision(1) << fixed << -1.0;
}