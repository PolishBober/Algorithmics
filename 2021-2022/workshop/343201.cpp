#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
pair <int, int> enemies[maxn];
pair <int, double> collision[maxn];


bool compare(pair <int, double> a, pair <int, double> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair <int, int> ship;
    cin >> ship.first >> ship.second;
    for(int i = 0; i < n; ++i)
        cin >> enemies[i].first >> enemies[i].second;
    for(int i = 0; i < n; ++i) {
        collision[i].first = i + 1;
        if(enemies[i].second <= ship.second)
            collision[i].second = 1e6;
        else
            collision[i].second = double(ship.first - enemies[i].first) / double(enemies[i].second - ship.second);
    }
    sort(collision, collision+n, compare);
    for(int i = 0; i < n; ++i) {
        if(i > collision[i].second) {
            cout << "GAME OVER";
            return 0;
        }
    }
    for(int i = 0; i < n; ++i)
        cout << collision[i].first << " ";
}