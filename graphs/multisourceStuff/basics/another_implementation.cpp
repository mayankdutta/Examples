/**
 *    author:  tourist
 *    created: 04.05.2019 15:28:26       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (int i = 0; i < h; i++) {
    cin >> grid[i];
  }
  vector<vector<int>> dist(h, vector<int>(w, -1));
  vector<pair<int, int>> que;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '#') {
        que.emplace_back(i, j);
        dist[i][j] = 0;
      }
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx * dx + dy * dy == 1) {
          int xk = que[b].first + dx;
          int yk = que[b].second + dy;
          if (xk >= 0 && yk >= 0 && xk < h && yk < w && dist[xk][yk] == -1) {
            que.emplace_back(xk, yk);
            dist[xk][yk] = dist[que[b].first][que[b].second] + 1;
          }
        }
      }
    }
  }
  cout << dist[que.back().first][que.back().second] << '\n';
  return 0;
}

