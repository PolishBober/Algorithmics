#include <iostream>
using namespace std;

int nwd(int a, int b) {
    if(a > b)
        swap(a, b);
    while(a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int z, n, d;
    cin >> z;
    for(int i = 0; i < z; ++i) {
        cin >> n >> d;
        cout << n / nwd(n, d) << "\n";
    }
}