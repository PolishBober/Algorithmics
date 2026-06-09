#include <bits/stdc++.h>
using namespace std;
vector <int> letters1[26], letters2[26];

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    string word1, word2;
    cin >> word1 >> word2;
    int substrings[word1.size()][word2.size()];
    for(int y = 0; y < word1.size(); ++y) {
        for(int x = 0; x < word2.size(); ++x) {
            if(y == 0 && x == 0)
                substrings[y][x] = (word1[y] == word2[x]);
            else if(y == 0)
                substrings[y][x] = max(substrings[y][x - 1], int(word1[y] == word2[x]));
            else if(x == 0)
                substrings[y][x] = max(substrings[y - 1][x], int(word1[y] == word2[x]));
            else
                substrings[y][x] = max(max(substrings[y - 1][x], substrings[y][x - 1]), substrings[y - 1][x - 1] + int(word1[y] == word2[x]));
        }
    }
    cout << substrings[word1.size() - 1][word2.size() - 1] << "\n";
    int y = word1.size() - 1, x = word2.size() - 1;
    string substring;
    while(y && x) {
        if(word1[y] == word2[x] && substrings[y - 1][x - 1] + 1 == substrings[y][x]) {
            substring += word1[y];
            --x;
            --y;
        }
        else if(x > 0 && substrings[y][x - 1] == substrings[y][x])
            --x;
        else if(y > 0 && substrings[y - 1][x] == substrings[y][x])
            --y;
        if(!x && substrings[y][x])
            substring += word2[0];
        else if(!y && substrings[y][x])
            substring += word1[0];
    }
    for(int i = substring.size() - 1; i >= 0; --i)
        cout << substring[i];
}