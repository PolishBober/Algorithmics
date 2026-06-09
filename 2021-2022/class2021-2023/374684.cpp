#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string word;
    for(int i = 0; i < n; ++i) {
        cin >> word;
        for(int j = 0; j < word.size(); ++j) {
            if(word[j] == 'g')
                word[j] = 'a';
            else if(word[j] == 'd')
                word[j] = 'e';
            else if(word[j] == 'r')
                word[j] = 'y';
            else if(word[j] == 'p')
                word[j] = 'o';
            else if(word[j] == 'l')
                word[j] = 'u';
            else if(word[j] == 'k')
                word[j] = 'i';
            else if(word[j] == 'a')
                word[j] = 'g';
            else if(word[j] == 'e')
                word[j] = 'd';
            else if(word[j] == 'y')
                word[j] = 'r';
            else if(word[j] == 'o')
                word[j] = 'p';
            else if(word[j] == 'u')
                word[j] = 'l';
            else if(word[j] == 'i')
                word[j] = 'k';
        }
        cout << word << " ";
    }
}