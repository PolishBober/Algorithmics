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
    long long distances1[n + 1];
    for(int i = 1; i <= n; ++i)
        distances1[i] = m * (long long)(1e6) + 1;
    distances1[1] = 0;
    todo.push({0, 1});
    while(!todo.empty()) {
        pair <long long, long long> top = todo.top();
        todo.pop();
        if(distances1[top.second] != top.first)
            continue;
        for(int branch = 0; branch < graph[top.second].size(); ++branch) {
            pair <long long, long long> shortbranch = graph[top.second][branch];
            if(distances1[shortbranch.second] > distances1[top.second] + shortbranch.first) {
                distances1[shortbranch.second] = distances1[top.second] + shortbranch.first;
                todo.push({distances1[shortbranch.second], shortbranch.second});
            }
        }
    }
    long long distances2[n + 1];
    for(int i = 1; i <= n; ++i)
        distances2[i] = m * (long long)(1e6) + 1;
    distances2[n] = 0;
    todo.push({0, n});
    while(!todo.empty()) {
        pair <long long, long long> top = todo.top();
        todo.pop();
        if(distances2[top.second] != top.first)
            continue;
        for(int branch = 0; branch < graph[top.second].size(); ++branch) {
            pair <long long, long long> shortbranch = graph[top.second][branch];
            if(distances2[shortbranch.second] > distances2[top.second] + shortbranch.first) {
                distances2[shortbranch.second] = distances2[top.second] + shortbranch.first;
                todo.push({distances2[shortbranch.second], shortbranch.second});
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        if(distances1[i] + distances2[i] == distances1[n])
            cout << i << "\n";
}