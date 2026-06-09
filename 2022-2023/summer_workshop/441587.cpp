#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e6;
ll tab[maxn + 1];
ll n;

ll binsearch(ll number) {
  ll beg = 0, end = maxn + 2;
  while(beg < end - 1) {
    ll mid = (beg + end) / 2;
    if(tab[mid] < number)
      beg = mid;
    else
      end = mid;
  }
  return end;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(ll i = 1; i < maxn + 1; ++i)
    tab[i] = INT_MAX;
  cin >> n;
  ll dificulty, answer = 0;
  for(ll i = 0; i < n; ++i) {
    cin >> dificulty;
    ll index = binsearch(dificulty);
    tab[index] = dificulty;
    if(index > answer)
      answer = index;
  }
  cout << answer << '\n';
  return 0;
}