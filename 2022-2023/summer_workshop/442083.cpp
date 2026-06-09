#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e3;
ll board[4][maxn + 2][maxn + 2];
ll distances1[4][maxn + 2][maxn + 2];
ll distances2[4][maxn + 2][maxn + 2];

struct Coordinates {
  ll z, y, x;
};

queue <Coordinates> todo;
Coordinates patrycja;
Coordinates rsa;
Coordinates treasure;
bool key = false;
// $ -1
// # 0
// . 1
// | 2
// K 3
// X 4

vector <Coordinates> directions = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

bool available(Coordinates & position, Coordinates & direction, ll distances[4][maxn + 2][maxn + 2]) {
  ll z = position.z;
  ll y = position.y;
  ll x = position.x;
  if(direction.z && board[z][y][x] == 2 && board[z + direction.z][y][x] && distances[z + direction.z][y][x] < 0)
    return true;
  else if(board[z][y + direction.y][x + direction.x] && distances[z][y + direction.y][x + direction.x] < 0) {
    if(key)
      return true;
    else if(board[z][y + direction.y][x + direction.x] > 0)
      return true;
  }
  return false;
}

void bfs(Coordinates position, ll distances[4][maxn + 2][maxn + 2]) {
  for(ll i = 0; i < 4; ++i)
    for(ll j = 0; j < maxn + 2; ++j)
      for(ll k = 0; k < maxn + 2; ++k)
        distances[i][j][k] = -1;
  todo.push(position);
  distances[position.z][position.y][position.x] = 0;
  while(!todo.empty()) {
    Coordinates top = todo.front();
    todo.pop();
    for(auto direction : directions) {
      if(available(top, direction, distances)) {
        distances[top.z + direction.z][top.y + direction.y][top.x + direction.x] = distances[top.z][top.y][top.x] + 1;
        todo.push({top.z + direction.z, top.y + direction.y, top.x + direction.x});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll h, w;
  cin >> h >> w;
  char character;
  for(ll z = 1; z <= 2; ++z) {
    for(ll y = 1; y <= h; ++y) {
      for(ll x = 1; x <= w; ++x) {
        cin >> character;
        if(character == '$')
          board[z][y][x] = -1;
        else if(character == '#')
          board[z][y][x] = 0;
        else if(character == '.')
          board[z][y][x] = 1;
        else if(character == '|')
          board[z][y][x] = 2;
        else if(character == 'K') {
          board[z][y][x] = 3;
          rsa = {z, y, x};
        }
        else if(character == 'X') {
          board[z][y][x] = 4;
          treasure = {z, y, x};
        }
        else {
          board[z][y][x] = 1;
          patrycja = {z, y, x};
        }
      }
    }
  }
  bfs(patrycja, distances1);
  if(distances1[treasure.z][treasure.y][treasure.x] > 0) {
    if(distances1[rsa.z][rsa.y][rsa.x] > 0) {
      key = true;
      bfs(rsa, distances2);
      if(distances1[rsa.z][rsa.y][rsa.x] + distances2[treasure.z][treasure.y][treasure.x] + 1 > distances1[treasure.z][treasure.y][treasure.x])
        cout << distances1[treasure.z][treasure.y][treasure.x] << '\n';
      else
        cout << distances1[rsa.z][rsa.y][rsa.x] + distances2[treasure.z][treasure.y][treasure.x] + 1 << '\n';
    }
    else
      cout << distances1[treasure.z][treasure.y][treasure.x] << '\n';
  }
  else {
    if(distances1[rsa.z][rsa.y][rsa.x] > 0) {
      key = true;
      bfs(rsa, distances2);
      if(distances2[treasure.z][treasure.y][treasure.x] > 0)
        cout << distances1[rsa.z][rsa.y][rsa.x] + distances2[treasure.z][treasure.y][treasure.x] + 1 << '\n';
      else
        cout << -1 << '\n';
    }
    else
      cout << -1 << '\n';
  }
  return 0;
}