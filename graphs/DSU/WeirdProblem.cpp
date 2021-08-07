/*
 * We were given the "from, to, weight" data of a MST
 * and we were supposed to find the minimum sum b/w every u and v, {u = [1, n], v = [1, n] }
 * this algo weirdly get us our ans.

 5
 1 2 1
 2 3 5
 3 4 3
 4 5 2

 D(1,2) =    D(1,3) =    D(1,4) = D(1,5) = 1
 D(2,3) = 5, D(2,4) = 3, D(2,5) = 2
 D(3,4) = 3, D(3,5) = 2
 D(4,5) = 2
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
struct UnionFind {
  int n, set_size, *parent, *rank;
  UnionFind() {}
  UnionFind(int a) {
    n = set_size = a;
    parent = new int[n + 1];
    rank = new int[n + 1];
    for (int i = 1; i <= n; ++i)
      parent[i] = i, rank[i] = 1;
  }
  int find(int x) {
    if (x != parent[x])
      return parent[x] = find(parent[x]);
    return x;
  }
  void merge(int x, int y) {
    int xroot = find(x), yroot = find(y);
    if (xroot != yroot) {
      if (rank[xroot] >= rank[yroot]) {
        parent[yroot] = xroot;
        rank[xroot] += rank[yroot];
      } else {
        parent[xroot] = yroot;
        rank[yroot] += rank[xroot];
      }
      set_size -= 1;
    }
  }
  void reset() {
    set_size = n;
    for (int i = 1; i <= n; i++)
      parent[i] = i, rank[i] = 1;
  }
  int size() { return set_size; }
  void print() {
    for (int i = 1; i <= n; ++i)
      cout << i << " -> " << parent[i] << "\n";
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int testcases;
  cin >> testcases;
  while (testcases--) {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    UnionFind uf(n);
    for (int i = 1; i <= n - 1; i++) {
      int u, v, weight;
      cin >> u >> v >> weight;
      edges.push_back({weight, {u, v}});
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    long long ans = 0;
    for (auto edge : edges) {
      int u = edge.second.first;
      int v = edge.second.second;

      int weight = edge.first;

      int rootU = uf.find(u);
      int rootV = uf.find(v);

      assert(rootU != rootV);

      ans = ans + (1LL * (uf.rank[rootU]) * (uf.rank[rootV]) * weight);
      uf.merge(u, v);
    }
    cout << ans << "\n";
  }
}

