#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 1;

bool prime(int number) {
    for(int i = 2; i <= sqrt(number); ++i)
        if(!(number % i) && number != i)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> sum;
        for(int i = sum / 2 - !(sum % 4); i > 1; i -= 2) {
            if(prime(i) && prime(sum - i)) {
                cout << i << " " << sum - i << "\n";
                break;
            }
        }
    }
}