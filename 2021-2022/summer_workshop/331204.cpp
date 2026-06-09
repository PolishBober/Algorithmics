#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int h[n];
    for(int i = 0; i < n; ++i)
        cin >>h[i];
    int maxlength = 0;
    for(int i = 0; i < n; ++i) {
        for(int direction = -1; direction < 2; direction += 2) {
            int cost = k, length = 0;
            while((cost >= 0 && i + (length + 1) * direction >= 0 && direction == -1) || (cost >= 0 && i + (length + 1) * direction < n && direction == 1)) {
                if(h[i + length * direction] < h[i + (length + 1) * direction]) {
                    cost -= h[i + (length + 1) * direction] - h[i + length * direction];
                    if(cost >= 0)
                        length += 1;
                }
                else
                    length += 1;
            }
            if(maxlength < length + 1)
                maxlength = length + 1;
        }
    }
    cout << maxlength;
}//sjhd