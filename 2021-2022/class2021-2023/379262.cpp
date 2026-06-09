#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string type, text;
  int k;
  cin >> type;
  cin >> k;
  cin.ignore();
  getline(cin, text);
  if(type == "odszyfruj")
    k = -k;
  for(int i = 0; i < text.size(); ++i) {
    if(64 < text[i] && text[i] < 91) {
      if((text[i] - 'A' + k) % 26 < 0)
        text[i] = 'A' + 26 + (text[i] - 'A' + k) % 26;
      else
        text[i] = 'A' + (text[i] - 'A' + k) % 26;
    }
    else if(96 < text[i] && text[i] < 123) {
      if((text[i] - 'a' + k) % 26 < 0)
        text[i] = 'a' + 26 + (text[i] - 'a' + k) % 26;
      else
        text[i] = 'a' + (text[i] - 'a' + k) % 26;

    }
  }
  cout << text;
}