/**
 *   @FileName	a.cpp
 *   @Author	kanpurin | AC
 *   @Created	2021.08.29 22:57:14
 **/

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

struct DAG {
private:
  struct Edge {
    int to;
  };
  std::vector<std::vector<Edge>> graph;
  bool is_dag = false;
  std::vector<int> sorted;
  int V;

public:
  DAG(int v) {
    assert(v > 0);
    V = v;
    graph.resize(v);
  }

  void add_edge(int from, int to) { graph[from].push_back({to}); }

  std::vector<int> topological_sort() {
    std::stack<int> sta;

    std::vector<int> in(V, 0);
    int used_cnt = 0;
    for (int i = 0; i < V; i++) {
      for (Edge e : graph[i]) {
        in[e.to]++;
      }
    }
    for (int i = 0; i < V; i++)
      if (in[i] == 0) {
        sta.push(i);
        used_cnt++;
      }
    while (!sta.empty()) {
      int p = sta.top();
      sta.pop();
      sorted.push_back(p);
      for (Edge e : graph[p]) {
        int v = e.to;
        in[v]--;

        if (in[v] == 0) {
          sta.push(v);
          used_cnt++;
        }
      }
    }
    if (used_cnt == V) {
      return sorted;
    } else {
      return std::vector<int>(0);
    }
  }
  vector<Edge> &operator[](int x) { return graph[x]; }
};
int main() {
  int n, m;
  cin >> n >> m;
  DAG g(n);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    int pre = -1;
    for (int j = 0; j < k; j++) {
      int a;
      cin >> a;
      a--;
      if (pre != -1)
        g.add_edge(pre, a);
      pre = a;
    }
  }
  auto v = g.topological_sort();
  if (v.size() == 0) {
    puts("No");
  } else {
    puts("Yes");
  }
  return 0;
}
