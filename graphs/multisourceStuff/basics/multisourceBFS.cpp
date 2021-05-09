/*
 * Technique used multisource BFS
 * all the sources moved to queue at the begining
 * and then the normal BFS resumed.
 * soruce: https://atcoder.jp/contests/agc033/tasks/agc033_a
 */

#include <bits/stdc++.h>

using namespace std;

#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define pii pair<int, int>

void solve() {
  int dr[] = {1, -1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  vvc grid; vvb used; vvi distance;

  int n; cin >> n;
  int m; cin >> m;

  grid.resize(n + 1); for (auto& i: grid) i.resize(m + 1);
  used.resize(n + 1); for (auto& i: used) i.resize(m + 1, false);
  distance.resize(n + 1); for (auto& i: distance) i.resize(m + 1, 0);

  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];

  queue<pii> qu;
  int ans = 0;

  /* multisource step */
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    if (grid[i][j] == '#') qu.push({i, j}), used[i][j] = true;

  while (!qu.empty()) {
    auto current = qu.front();
    qu.pop();

    for (int i = 0; i < 4; i++) {
      int rr = dr[i] + current.first;
      int cc = dc[i] + current.second;

      if (rr < 0 or rr >= n or cc < 0 or cc >= m) continue;
      if (used[rr][cc]) continue;

      used[rr][cc] = true;
      grid[rr][cc] = '#';
      distance[rr][cc] = distance[current.first][current.second] + 1;
      ans = max(distance[rr][cc], ans);
      qu.push({rr, cc});
    }
  }
  cout << ans << '\n';
}

int main() {
  int t = 1;
  while (t--)
    solve();
}
