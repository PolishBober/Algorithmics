#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string word;
    cin >> word;
    int a = 0;
    for(int i = 0; i < word.size(); ++i)
        if(word[i] == 97 || word[i] == 65)
            a++;
    cout << a;
}