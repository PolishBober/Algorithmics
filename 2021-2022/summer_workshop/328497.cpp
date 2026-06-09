#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    long long board[n][3];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }
    for(int i = 1; i < n; ++i) {
        board[i][0] += max(board[i - 1][1], board[i - 1][2]);
        board[i][1] += max(board[i - 1][0], board[i - 1][2]);
        board[i][2] += max(board[i - 1][0], board[i - 1][1]);
    }
    cout << max(max(board[n - 1][0], board[n - 1][1]), board[n - 1][2]);
}