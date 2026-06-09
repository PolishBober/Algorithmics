#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const ll maxn = 1e6;
ll a[maxn];
ld b[maxn], tab[maxn];
ll n, maxa;

bool condition(ld mid) {
  for(ll i = 0; i < n; ++i) {
    if(!i)
      tab[i] = a[i] - mid;
    else
      tab[i] = max((ld)min(a[i] - mid, a[i] + mid), tab[i - 1]);
    if(abs(a[i] - tab[i]) > mid)
      return false;
  }
  for(ll i = 0; i < n; ++i)
    b[i] = tab[i];
  return true;
}

void binsearch() {
  ld beg = 0, end = maxa;
  while(beg < end - 0.00001) {
    ld mid = (beg + end) / 2;
    if(!condition(mid))
      beg = mid;
    else
      end = mid;
  }
  cout << fixed << setprecision(3) << end << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(ll i = 0; i < n; ++i) {
    cin >> a[i];
    if(maxa < abs(a[i]))
      maxa = abs(a[i]);
  }
  binsearch();
  for(ll i = 0; i < n; ++i)
    cout << fixed << setprecision(3) << b[i] << '\n';
  return 0;
}