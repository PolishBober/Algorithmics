#include <bits/stdc++.h>
using namespace std;
int malphabet[26], dalphabet[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string word;
    for(int i = 0; i <= n; ++i) {
        getline(cin, word);
        for(int j = 0; j < word.size(); ++j) {
            if(word[j] < 97)
                ++dalphabet[word[j] - 65];
            else
                ++malphabet[word[j] - 97];
        }
    }
    for(int j = 0; j < 26; ++j)
        if(malphabet[j])
            cout << char(j + 97) << " " << malphabet[j] << "\n";
    for(int j = 0; j < 26; ++j)
        if(dalphabet[j])
            cout << char(j + 65) << " " << dalphabet[j] << "\n";
}