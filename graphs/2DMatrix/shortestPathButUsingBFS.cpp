/*
 * Shortest path but using BFS
 * Motivating problem: https://cses.fi/problemset/task/1193/
 *
 *
 * Better to use this, you never know when to use what
 * int Dr[] = {1, -1, 0, 0, 1, 1, -1, -1};
 * int Dc[] = {0, 0, 1, -1, -1, 1, 1, -1};
 * 
 * int dr[] = {1, -1, 0, 0}; 
 * int dc[] = {0, 0, 1, -1};
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive that this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string stepDir = "URDL";

int main() {
  cin >> n >> m;

  queue<ii> q;
  ii begin, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
      if (A[i][j] == 'A') {
        begin = mp(i, j);
      } else if (A[i][j] == 'B') {
        end = mp(i, j);
      }
    }
  }

  q.push(begin);
  vis[begin.f][begin.s] = true;

  while (!q.empty()) {
    ii u = q.front(); 
    q.pop();
    for (int i = 0; i < 4; i++) {
      // ii v = mp(u.f + dx[i], u.s + dy[i]);
      int r = u.f + dx[i];
      int c = u.s + dy[i];

      // if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
      // if (A[v.f][v.s] == '#') continue;

      if (r < 0 or r >= n or c < 0 or c >= m) continue;
      if (A[r][c] == '#') continue;
      if (vis[r][c]) continue;

      vis[r][c] = true;

      // vis[v.f][v.s] = true;
      // previousStep[v.f][v.s] = i;

      previousStep[r][c] = i;
      q.push({r, c});
      // q.push(v);
    }
  }

  if (vis[end.f][end.s]) {
    cout << "YES" << endl;
    vector<int> steps;
    while (end != begin) {
      int p = previousStep[end.f][end.s];
      steps.push_back(p);
      // undo the previous step to get back to the previous square
      // Notice how we subtract dx/dy, whereas we added dx/dy before
      end = mp(end.f - dx[p], end.s - dy[p]);
    }
    reverse(steps.begin(), steps.end());

    cout << steps.size() << endl;
    for (char c : steps) {
      cout << stepDir[c];
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}

/* Pay extra attention to dx, dy and stepDir
 * Pay extra attention to how they store paths
 * Try not to get confuse in dr, and dc make them on paper, They mean exact opposite .... yes try to visualize them. 
 * Solution link: https://usaco.guide/solutions/cses-1193?lang=cpp
 */
