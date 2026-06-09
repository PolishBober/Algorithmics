#include <bits/stdc++.h>
using namespace std;
bool view[2000][2000];
int viewtrees[int(4e6)];
int counttrees[2000][2000];
int pref[2000][2000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    view[0][0] = true;
    int m, n, trees = 0;
    cin >> m >> n;
    for(int y = 0; y < m; ++y) {
        for(int x = 0; x < n; ++x) {
            if(!view[y][x]) {
                int multiple = 2;
                while(y * multiple < m && x * multiple < n) {
                    view[y * multiple][x * multiple] = true;
                    ++multiple;
                }
                ++trees;
            }
        }
    }
    for(int x = 0; x < n; ++x) {
        for(int y = 0; y < m; ++y) {
            pref[y][x] = !view[y][x];
            if(y)
                pref[y][x] += pref[y - 1][x];
        }
    }
    int maxtrees = trees;
    for(int y = 0; y < m; ++y) {
        if(y) {
            for(int i = 0; i < n; ++i)
                if(!view[m - y][i])
                    --trees;
            for(int i = 0; i < n; ++i)
                if(!view[y][i])
                    ++trees;
        }
        for(int x = 0; x < n; ++x) {
            if(x) {
                trees += pref[m - y - 1][x] + pref[y][x] - pref[0][x] - pref[m - y - 1][n - x] - pref[y][n - x] + pref[0][n - x];
            }
            if(trees > maxtrees)
                maxtrees = trees;
            viewtrees[trees] += 1;
        }
    }
    cout << maxtrees << " " << viewtrees[maxtrees];
}