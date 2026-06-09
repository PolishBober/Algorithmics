#include <bits/stdc++.h>
using namespace std;

int sum(int number) {
    return (number / 1000) * 1000 + (number - (number / 100) * 100 - ((number - (number / 100) * 100) / 10) * 10) * 100 + ((number - (number / 100) * 100) / 10) * 10 + number / 100;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair <int, int> contacts[n];
    for(int i = 0; i < n; ++i) {
        cin >> contacts[i].second;
        contacts[i].first = sum(contacts[i].second);
    }
    sort(contacts, contacts + n);
    for(int i = 0; i < n; ++i)
        cout << contacts[i].second << " ";
}