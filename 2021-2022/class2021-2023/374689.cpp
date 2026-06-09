#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string word;
    getline(cin, word);
    string newword = "";
    for(int i = 0; i < word.size(); ++i) {
        if(word[i] != ' ') {
            if(word[i] == 'u' || word[i] == 'U')
                newword += 'V';
            else if(word[i] < 97)
                newword += word[i];
            else
                newword += word[i] - 32;
        }
    }
    cout << newword;
}