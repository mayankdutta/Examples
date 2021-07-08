## Hint 1

```
Reverse all query operations. And instead of removing the edge, the query will be adding an edge in the graph.
```

## Complete Approach
```
The trick in the problem is to reverse the queries. Instead of addressing them ONLINE, we can solve them OFFLINE. First, we only add those edges in the graph, which have never occurred in any removal query.
Now after reversing the queries, the removal query is now an addition query. Add the edge in the graph for the first type of query.
For 2nd type of query, find the number of connected components and stored it somewhere at the appropriate index, which is according to the original queries.
And print the answer in proper order. The time and space complexities are the same as DSU.

Time complexity: Without path compression: O(NlogN) & With path compression: O(N)
Space complexity: O(N + M + Q) extra space

```
## Implementation

```
#include <iostream>
#include <vector>
#define Size 1e5
using namespace std;

/* old template */
class UnionFind {
public:
  vector<int> parent, rank;
  int count;
  UnionFind(int n) {
    parent.resize(Size, 0);
    rank.resize(Size, 0);

    for (int i = 1; i <= n; i++)
      parent[i] = i;
    count = n - 1; /* To create record of unique elements. */
  }
  int find(int n) { return (n == parent[n] ? n : parent[n] = find(parent[n])); }
  bool isSame(int a, int b) { return find(a) == find(b); }
  void merge(int a, int b) {
    int parent_a = find(a);
    int parent_b = find(b);
    if (parent_a == parent_b)
      return;

    if (rank[parent_a] > rank[parent_b]) {
      parent[parent_b] = parent_a;
    } else {
      parent[parent_a] = parent_b;
      if (rank[parent_a] == rank[parent_b]) {
        rank[parent_b]++;
      }
    }
    count--;
  }
};

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<pair<int, int>> edge, queries;
  edge.push_back({0, 0});
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    edge.push_back({a, b});
  }

  vector<int> marked(Size, 0);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a;

    if (a == 2) {
      queries.push_back({2, 0});
    } else {
      cin >> b;
      queries.push_back({a, b});
      marked[b] = 1;
    }
  }

  vector<int> ans;
  UnionFind dsu(n + 1);

  for (int i = 1; i <= m; i++) {
    if (!marked[i]) {
      dsu.merge(edge[i].first, edge[i].second);
    }
  }

  for (int i = q - 1; i >= 0; i--) {
    if (queries[i].first == 2) {
      ans.push_back(dsu.count);
    } else {
      int u = queries[i].second;
      dsu.merge(edge[u].first, edge[u].second);
    }
  }

  reverse(ans.begin(), ans.end());
  for (const auto &i : ans) {
    cout << i << '\n';
  }
}
```
