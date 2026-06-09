#include <bits/stdc++.h>
using namespace std;

priority_queue <pair<long long, long long>, vector <pair<long long, long long>>, greater<pair<long long, long long>>> todo;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair<long long, long long>> graph[n + 1];
    long long a, b, w;
    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }
    long long distances[n + 1];
    for(int i = 1; i <= n; ++i)
        distances[i] = m * (long long)(1e6) + 1;
    distances[1] = 0;
    todo.push({0, 1});
    while(!todo.empty()) {
        pair <long long, long long> top = todo.top();
        todo.pop();
        if(distances[top.second] != top.first)
            continue;
        for(int branch = 0; branch < graph[top.second].size(); ++branch) {
            pair <long long, long long> shortbranch = graph[top.second][branch];
            if(distances[shortbranch.second] > distances[top.second] + shortbranch.first) {
                distances[shortbranch.second] = distances[top.second] + shortbranch.first;
                todo.push({distances[shortbranch.second], shortbranch.second});
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(distances[i] == m * (long long)(1e6) + 1)
            cout << -1 << "\n";
        else
            cout << distances[i] << "\n";
    }
}