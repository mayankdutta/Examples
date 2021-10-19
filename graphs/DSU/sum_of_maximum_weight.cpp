// https://atcoder.jp/contests/abc214/tasks/abc214_d
// https://codeforces.com/blog/entry/93842 to checkout no. of same problems 

#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
  std::vector<int> Parent;
  std::vector<int> Size;

  void init(int n) {
    /* You may want to change the size. */
    Size.resize(int(3e5) + 5, 1);
    Parent.resize(int(3e5) + 5, 0);

    for (int i = 0; i < n; i++)
      Parent[i] = i;
  }

  void makeSet(int n) {
    Parent[n] = n;
    Size[n] = 1;
  }

  int findSet(int i) {
    return (Parent[i] == i) ? i : (Parent[i] = findSet(Parent[i]));
  }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b)
      return;
    if (Size[a] < Size[b])
      std::swap(a, b);

    Parent[b] = a;
    Size[a] += Size[b];
    // debug2(Size[a], Size[b]);
  }
} dsu;

int main() {
  int n;
  cin >> n;

  vector<tuple<long long int, long long int, long long int>> edges(n - 1);
  for (auto &[w, u, v] : edges)
    cin >> u >> v >> w;

  sort((edges).begin(), (edges).end());
  dsu.init(n + 10);

  // for (const auto &[w, u, v] : edges) debug3(w, u, v);

  long long int ans = 0;
  for (const auto &[w, u, v] : edges) {
    ans += w * dsu.Size[dsu.findSet(u)] * dsu.Size[dsu.findSet(v)];
    dsu.unionSet(u, v);
  }
  cout << ans << '\n';
}
