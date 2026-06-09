#include <iostream>
#include <string>
using namespace std;
int slist[26];

bool in(string text, char letter) {
    for(int i = 0; i < text.size() + 1; ++i)
        if(text[i] == letter)
            return true;
    return false;
}

int anothers(string text, int a, int b) {
    string letters = "";
    for(int i = a; i < b; ++i)
        if(!in(letters, text[i]))
            letters += text[i];
    return letters.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int k;
    cin >> n >> k;
    int sum = anothers(n, 0, n.size() + 1);
    if(sum >= k) {
        int a = 0, b = k, spectacles = 0, answer[2] = {0, n.size() + 1};
        spectacles = anothers(n, 0, k);
        for(int i = 0; i < k; ++i)
            slist[int(n[i]) - 97] += 1;
        for(int i = 0; i < n.size() - k; ++i) {
            if(spectacles == k) {
                while(slist[int(n[a]) - 97] > 1) {
                    --slist[int(n[a]) - 97];
                    ++a;
                }
                if(answer[1] - answer[0] > b - a) {
                    answer[0] = a;
                    answer[1] = b;
                    if(answer[1] - answer[0] == k) {
                        cout << answer[0] + 1 << " " << answer[1];
                        return 0;
                    }
                }
                if(slist[int(n[a]) - 97] == 1)
                    --spectacles;
                --slist[int(n[a]) - 97];
                ++a;
            }
            if(slist[int(n[b]) - 97] == 0)
                ++spectacles;
            ++slist[int(n[b]) - 97];
            ++b;
        }
        cout << answer[0] + 1 << " " << answer[1];
    }
    else
        cout << "BRAK";
}