#include <bits/stdc++.h>
using namespace std;
int alphabet[26];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  char letter;
  string text;
  cin >> n >> letter >> text;
  pair <int, int> max = {0, 0};
  for(int i = 0; i < text.size(); ++i) {
    ++alphabet[text[i] - 'A'];
    if(alphabet[text[i] - 'A'] > max.first)
      max = {alphabet[text[i] - 'A'], text[i] - 'A'};
  }
  int k = letter - 'A' - max.second;
  for(int i = 0; i < text.size(); ++i) {
    if((text[i] - 'A' + k) % 26 < 0)
      text[i] = 'A' + 26 + (text[i] - 'A' + k) % 26;
    else
      text[i] = 'A' + (text[i] - 'A' + k) % 26;
  }
  cout << text;
}