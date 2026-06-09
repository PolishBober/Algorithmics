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
            if(word[j] >= 97)
                word[j] = word[j] - 32;
        }
        cout << word << "\n";
    }
}