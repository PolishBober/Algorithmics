#include <bits/stdc++.h>
using namespace std;
vector <int> letters1[26], letters2[26];

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    string word1, word2;
    cin >> word1 >> word2;
    for(int i = 0; i < word1.size(); ++i)
        letters1[word1[i] - 97].push_back(i);
    for(int i = 0; i < word2.size(); ++i)
        letters2[word2[i] - 97].push_back(i);
    int size_ = word1.size();
    for(int i = 0; i < 26; ++i) {
        if(letters1[i].size() > letters2[i].size()) {
            for(int j = 0; j < word1.size(); ++j) {
                if(word1[j] == i + 97) {
                    word1[j] = ' ';
                    letters1[i].pop_back();
                    size_ -= 1;
                if(letters1[i].size() - letters2[i].size() <= 0)
                    break;
                }
            }
        }
        else if(letters1[i].size() < letters2[i].size()) {
            for(int j = 0; j < word2.size(); ++j) {
                if(word2[j] == i + 97) {
                    word2[j] = ' ';
                    letters2[i].pop_back();
                if(letters2[i].size() - letters1[i].size() <= 0)
                    break;
                }
            }
        }
    }
    if(size_ == 0)
        cout << "BRAK";
    else {
        cout << size_ << "\n";
        for(int i = 0; i < word1.size(); ++i)
            if(word1[i] != ' ')
                cout << word1[i];
        cout << "\n" << size_ << "\n";
        for(int i = 0; i < word2.size(); ++i)
            if(word2[i] != ' ')
                cout << word2[i];
    }
}