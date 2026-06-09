#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 2e3;
bool tab[maxn + 2][maxn + 2];
ll n, m;

struct Coordinates {
  ll y, x;
};

vector <Coordinates> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Worm {
  ll y, x;
  ll direction = 0;
  bool wall() {
    return tab[y - directions[direction].x][x + directions[direction].y];
  }
  void step() {
    y += directions[direction].y;
    x += directions[direction].x;
  }
  void rotate(bool right) {
    if(right)
      direction = (direction + 1) % 4;
    else
      direction = (4 + direction - 1) % 4;
  }
  void move() {
    if(wall()) {
      rotate(false);
      step();
    }
    else if(tab[y + directions[direction].y][x + directions[direction].x])
      step();
    else
      rotate(true);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  char help;
  for(ll y = 1; y <= n; ++y) {
    for(ll x = 1; x <= m; ++x) {
      cin >> help;
      tab[y][x] = (help == '.');
    }
  }
  for(ll y = 1; y <= n; ++y) {
    if(tab[y][1]) {
      ll maxy = 0;
      Worm worm;
      worm = {y, 1};
      while(worm.x < m && (worm.x > 1 || worm.direction < 3)) {
        worm.move();
        if(worm.y > maxy)
          maxy = worm.y;
      }
      if(worm.x <= 1)
        y = worm.y;
      if(worm.x == m) {
        cout << n - maxy << '\n';
        return 0;
      }
    }
  }
  cout << "NIE\n";
  return 0;
}