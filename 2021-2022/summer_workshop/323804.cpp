#include <iostream>
#include <iomanip>
using namespace std;
int episodes[(int)1e6][2];

double sumtime(int n, double x) {
    double time = 0;
    for(int i = 0; i < n; ++i)
        time += episodes[i][0] / (episodes[i][1] + x);
    return time;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; ++i) {
        cin >> episodes[i][0] >> episodes[i][1];
    }
    double a = 0, b = 5e4 + 1;
    while(b - a > 1e-9) {
        double between = (a + b) / 2;
        if(sumtime(n, between) <= t)
            b = between;
        else
            a = between;
    }
    cout << setprecision(9) << fixed << a;
}