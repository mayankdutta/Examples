/*
 * Motivation problem: https://codeforces.com/contest/755/problem/C
 * source: usaco.guide
 * Trees
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<bool> used;

void dfs(int parent) {
  used[parent] = true;
  for (const auto& child: adj[parent])
    if (!used[child])
      dfs(child);
}

int main() {
  int n;
  std::cin >> n;

  adj.resize(n + 1);
  used.resize(n + 1, false);

  int child = 1;
  for (int i = 0; i < n; i++) {
    int parent; std::cin >> parent;

    /* Was making mistake here */
    /*
     * adj[parent].push_back(child);
     *
     * simply using this, hence getting WA
     * should've declared a double edge like in undirected graph.
     */

    adj[parent].push_back(child);
    adj[child].push_back(parent);
    child ++;
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i);
      count ++;
    }
  }
  std::cout << count << '\n';
}

