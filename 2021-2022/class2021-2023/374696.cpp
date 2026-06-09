#include <bits/stdc++.h>
using namespace std;
int alphabet[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string word1, word2;
    cin >> word1 >> word2;
    if(word1.size() != word2.size()) {
        cout << "NIE";
        return 0;
    }
    for(int i = 0; i < word1.size(); ++i) {
        ++alphabet[word1[i] - 97];
        --alphabet[word2[i] - 97];
    }
    for(int i = 0; i < 26; ++i) {
        if(alphabet[i]) {
            cout << "NIE";
            return 0;
        }
    }
    cout << "TAK";
}