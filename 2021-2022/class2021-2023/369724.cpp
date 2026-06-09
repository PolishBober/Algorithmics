#include <bits/stdc++.h>
using namespace std;

bool comparison(string a, string b) {
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string jewelry[n];
    for(int i = 0; i < n; ++i)
        cin >> jewelry[i];
    sort(jewelry, jewelry + n, comparison);
    for(int i = 0; i < n; ++i)
        cout << jewelry[i] << "\n";
}