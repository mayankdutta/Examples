/*
 * Motivational Problem : https://cses.fi/problemset/task/1674/
 * simply have to use some sort of data structure to store the data.
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> Size;

void dfs(int parent) {
  for (const int& child: tree[parent]) {
    dfs(child);
    Size[parent] += Size[child];
  }
}

int main() {
  int n;
  cin >> n;

  tree.resize(n + 1);
  Size.resize(n + 1, 1);

  int child = 2;
  for (int i = 0; i < n - 1; i++) {
    int parent;
    cin >> parent;

    tree[parent].push_back(child);
    child ++;
  }

  dfs(1);

  for (int i = 1; i <= n; i++)
    cout << Size[i]  - 1 << ' ';
  cout << '\n';
}


