#include <iostream>
using namespace std;
const int maxn = 1e6;
int nlist[maxn];


int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> nlist[i];
    }
    int sum = 0;
    for(int i = 0; i < n; ++i)
        sum += nlist[i];
    if(sum >= k) {
        int a = 0, b = k, roses = 0, answer = n;
        for(int i = 0; i < k; ++i)
            roses += nlist[i];
        for(int i = 0; i < n - k; ++i) {
            if(roses == k) {
                while(nlist[a] == 0)
                    ++a;
                if(answer > b - a - k)
                    answer = b - a - k;
                    if(answer == 0) {
                        cout << answer;
                        return 0;
                    }
                if(nlist[a] == 1)
                    --roses;
                ++a;
                while(nlist[a] == 0)
                    ++a;
            }
            if(nlist[b] == 1)
                ++roses;
            ++b;
        }
        cout << answer;
    }
    else
        cout << "NIE";
}