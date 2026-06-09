#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Description {
  ll reprezentative, weight, iq_max, iq_min;
};

const ll maxn = 1e6;
Description tab[maxn + 1];

ll Find(ll reprezentative) {
  if(tab[reprezentative].reprezentative == reprezentative)
    return reprezentative;
  tab[reprezentative].reprezentative = Find(tab[reprezentative].reprezentative);
  return tab[reprezentative].reprezentative;
}

void Union(ll vertex1, ll vertex2) {
  if(Find(vertex1) != Find(vertex2)) {
    tab[Find(vertex2)].iq_max = max(tab[Find(vertex1)].iq_max, tab[Find(vertex2)].iq_max);
    tab[Find(vertex2)].iq_min = min(tab[Find(vertex1)].iq_min, tab[Find(vertex2)].iq_min);
    tab[Find(vertex2)].weight += tab[Find(vertex1)].weight;
    tab[Find(vertex1)].reprezentative = Find(vertex2);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  for(ll i = 1; i <= n; ++i) {
    cin >> tab[i].weight >> tab[i].iq_max;
    tab[i].reprezentative = i;
    tab[i].iq_min = tab[i].iq_max;
  }
  string type;
  ll a, b;
  while(cin >> type >> a) {
    if(type == "JOIN") {
      cin >> b;
      Union(a, b);
    }
    else if(type == "IQ_MAX")
      cout << tab[Find(a)].iq_max << '\n';
    else if(type == "IQ_MIN")
      cout << tab[Find(a)].iq_min << '\n';
    else
      cout << tab[Find(a)].weight << '\n';
  }
  return 0;
}