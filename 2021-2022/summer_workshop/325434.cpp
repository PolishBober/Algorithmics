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
    int n;
    cin >> n;
    int a, b;
    cin >> a;
    for(int i = 1; i < n; ++i) {
        cin >> b;
        a = nwd(a, b);
    }
    cout << a;
}