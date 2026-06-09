#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, t;
    double x;
    cin >> n >> t >> x;
    int episodes[n][2];
    for(int i = 0; i < n; ++i) {
        cin >> episodes[i][0] >> episodes[i][1];
    }
    double time = 0;
    for(int i = 0; i < n; ++i) {
        time += double(episodes[i][0]) / (episodes[i][1] + x);
    }
    if(time > t)
        cout << "NIE";
    else
        cout << "TAK";
}