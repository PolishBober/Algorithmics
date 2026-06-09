#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair <string, int> participants[n];
    int maxpoints = 0;
    vector <string> winners;
    for(int i = 0; i < n; ++i) {
        cin >> participants[i].first >> participants[i].second;
        if(maxpoints < participants[i].second) {
            winners.clear();
            maxpoints = participants[i].second;
        }
        if(maxpoints == participants[i].second)
            winners.push_back(participants[i].first);
    }
    for(int i = 0; i < winners.size(); ++i)
        cout << winners[i] << "\n";
}