#include <bits/stdc++.h>
#define ll long long
using namespace std;
string word;
ll alphabet[200];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> word;
  ll k;
  cin >> k;
  pair <ll, ll> answer = {-1, -1};
  ll end = 0, different = 0;
  for(ll beg = 1; beg <= word.size(); ++beg) {
    if(!alphabet[word[beg - 1]]++)
      ++different;
    while(different == k) {
      if(answer.first - answer.second > beg - end || answer.first < 0)
        answer = {beg, end};

      if(!--alphabet[word[end]])
        --different;
      ++end;
    }
  }
  if(answer.first < 0)
    cout << "BRAK";
  else
    cout << answer.second + 1 << ' ' << answer.first;
}