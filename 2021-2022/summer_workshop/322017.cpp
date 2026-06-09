#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x;
    cin >> x;
    double a = 0, between, b = x + 1;
    while(b - a > 0.01) {
        between = (a + b) / 2;
        if(between*between < x)
            a = between + 0.01;
        else if(between*between > x)
            b = between;
        else
            a = between;
    }
    cout << a;
}