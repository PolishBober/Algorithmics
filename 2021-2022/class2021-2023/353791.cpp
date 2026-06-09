#include <bits/stdc++.h>
using namespace std;
const int maxh = 5e5;
int walls[maxh];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h, a;
    cin >> n >> h;
    for(int i = 0; i < n; ++ i) {
        cin >> a;
        if(i % 2)
            ++walls[h - a];
        else {
            ++walls[0];
            --walls[a];
        }
    }
    for(int i = 1; i < h; ++i)
        walls[i] += walls[i - 1];
    pair <int, int> thickness = {INT_MAX, 0};
    for(int i = 0; i < h; ++i) {
        if(walls[i] < thickness.first) {
            thickness.first = walls[i];
            thickness.second = 1;
        }
        else if(walls[i] == thickness.first)
            ++thickness.second;
    }
    cout << thickness.first << " " << thickness.second;
}