#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int configurations[n + 1][m + 1], plate1[n + 1], plate2[m + 1];
    for(int i = 1; i < n + 1; ++i) {
        cin >> configurations[i][0];
        plate1[i] = configurations[i][0];
        if(i > 2)
            configurations[i][0] += configurations[i - 2][0];
    }
    for(int i = 1; i < m + 1; ++i) {
        cin >> configurations[0][i];
        plate2[i] = configurations[0][i];
        if(i > 2)
            configurations[0][i] += configurations[0][i - 2];
    }
    for(int y = 1; y < n + 1; ++y)
        for(int x = 1; x < m + 1; ++x)
            if(x < 2 && y < 2)
                configurations[y][x] = max(plate1[y], plate2[x]);
            else if(y < 2)
                configurations[y][x] = max(plate1[y] + configurations[y - 1][x - 1], plate2[x] + min(configurations[y - 1][x - 1], configurations[y][x - 2]));
            else if(x < 2)
                configurations[y][x] = max(plate1[y] + min(configurations[y - 1][x - 1], configurations[y - 2][x]), plate2[x] + configurations[y - 1][x - 1]);
            else
                configurations[y][x] = max(plate1[y] + min(configurations[y - 1][x - 1], configurations[y - 2][x]), plate2[x] + min(configurations[y - 1][x - 1], configurations[y][x - 2]));
    cout << configurations[n][m];
}