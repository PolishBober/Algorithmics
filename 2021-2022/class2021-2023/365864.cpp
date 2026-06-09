#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    int p, index0 = -1, index1 = -1, sum = 0, sum1 = 0;
    for(int i = 0; i < k + 1; ++i) {
        cin >> p;
        if(index0 < 0) {
            if(((sum - 2 * ((1<<i) - 1) + sum1) / (1<<i) + p) % 2) {
                if(!sum1)
                    index1 = i;
                sum1 += 1<<i;
            }
            else if(!p && !(sum - 2 * ((1<<i) - 1) + sum1))
                index0 = i;
            sum += p * (1<<i);
        }
    }
    if(index0 < 0) {
        index0 = k + 1;
        int zero = (sum - 2 * ((1<<k + 1) - 1) + sum1) / (1<<k + 1);
        while(zero) {
            if(zero % 2)
                sum1 += 1<<index0;
            ++index0;
            zero = (zero - 1) / 2;
        }
    }
    cout << 2 * ((1<<index0) - 1) - sum1 + 1;
}