#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if(board[i][j]) board[i][j] = 0;
            else board[i][j] = -1;
            if(i == 1 && j == 1) board[i][j] = 1;
            if(board[i][j] != 0) {
                if(board[i - 1][j] > 0) {
                    board[i][j] = board[i - 1][j];
                    if(board[i][j - 1] > 0)
                        board[i][j] += board[i][j - 1];
                }
                else
                    if(board[i][j - 1] > 0) board[i][j] = board[i][j - 1];
                board[i][j] %= int(1e6);
            }
        }
    }
    if(board[n][n] == -1) cout << 0;
    else cout << board[n][n];
}