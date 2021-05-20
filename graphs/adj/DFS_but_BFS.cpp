/*
 * source : https://codeforces.com/problemset/problem/1106/D
 * look like a DFS problem but it isn't
 */

#include <bits/stdc++.h>

using namespace std;
using ll=long long int;
using lld=long double;

#define mp make_pair
#define pb push_back
#define accu accumulate

#define vi vector<int>
#define vb vector<bool>

vector<set<int>> grid;
vb used;
vi ans;

void dfs(int n) {
  used[n] = true;
  for (const auto& i: grid[n]) {
    if (!used[i]) {
      ans.push_back(i);
      dfs(i);
    }
  }
}

void bfs(int n) {
  priority_queue<int, vector<int>, greater<int> > qu;
  qu.push(n);
  used[n] = true;

  while(!qu.empty()) {
    auto current = qu.top();
    qu.pop();
    used[current] = true;

    ans.push_back(current); /* needed step */
    for (const auto& i: grid[current]) {
      if (used[i]) continue;
      used[i] = true;

      /* Becuase data isn't in sorted form here, it will become one onece pushed to pq */
      // ans.push_back(current);

      qu.push(i);
    }
  }
}


int main() {
  int n, m;
  cin >> n >> m;

  grid.resize(n + 1);
  used = vb(n + 1, false);
  int start = INT_MAX;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    grid[a].insert(b);
    grid[b].insert(a);

    start = min(start, min(a, b));
  }

  bfs(start);
  for (const auto& i: ans) cout << i << ' '; cout << '\n';
}


