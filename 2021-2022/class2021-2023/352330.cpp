#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, sum = 1;
    cin >> n;
    for(int i = 2; i <= sqrt(n); ++i) {
        if(!(n % i)) {
            if(i != n / i)
                sum += n / i;
            sum += i;
        }
    }
    if(sum == n)
        cout << "TAK";
    else
        cout << sum;

}