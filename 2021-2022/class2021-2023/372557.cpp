#include <bits/stdc++.h>
using namespace std;
vector <char> line1 = {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='};
vector <char> line2 = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'};
vector <char> line3 = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''};
vector <char> line4 = {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};
vector <char> line5 = {' '};
vector <char> lines[5] = {line1, line2, line3, line4, line5};

bool in(char letter, int line) {
    for(int i = 0; i < lines[line].size(); ++i)
        if(letter == lines[line][i]) {
            return true;
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str, answer = "";
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i) {
        for(int j = 0; j < 5; ++j) {
            if(in(str[i], j)) {
                answer += to_string(j + 1);
                break;
            }
        }
    }
    cout << answer;
}