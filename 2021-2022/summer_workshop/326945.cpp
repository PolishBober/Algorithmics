#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    double average = 0;
    long long border = 0, x[n - 1];
    for(int i = 0; i < n - 1; ++i) {
        cin >> x[i];
        average += x[i];
        if(border < x[i] || border == 0)
            border = x[i];
    }
    long long maxb = average;
    average /= k;
    if(average > border) {
        if(int(average) == average)
            border = average;
        else
            border = average + 1;
    }

    long long a = border - 1, b = maxb;
    while(b - a > 1) {
        long long between = (a + b) / 2;
        long long index = 0, solution = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(solution + x[i] <= between)
                solution += x[i];
            else {
                solution = x[i];
                ++index;
            }
        }
        if(index + 1 > k)
            a = between;
        else
            b = between;
    }
    cout << b;
}