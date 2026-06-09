#include <bits/stdc++.h>
using namespace std;
int alphabet[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string word;
    for(int i = 0; i < n; ++i) {
        cin >> word;
        int brackets = 0;
        for(int j = 0; j < word.size(); ++j) {
            brackets += word[j] == '(';
            brackets -= word[j] == ')';
            if(brackets < 0 || word[j] != '(' && word[j] != ')')
                brackets = 300;
        }
        if(brackets)
            cout << "FALSE\n";
        else
            cout << "TRUE\n";
    }
}