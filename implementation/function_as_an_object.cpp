#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long double LD;
#define pb push_back
const lli mod = 1e9 + 7;
const lli mod1 = 998244353;
#define fir first
#define sec second
#define pplli pair<lli, plli>
#define ppplli pair<lli, pair<plli, plli>>
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

const lli SIZE = 200010;
vector<lli> graph[SIZE];

lli ans[SIZE];
lli Parent[SIZE], Rank[SIZE];

int main() {
  fastio;
  lli T = 1, i;
  while (T--) {
    lli n, m, x, y;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
      cin >> x >> y;
      graph[x].pb(y);
      graph[y].pb(x);
    }

    for (i = 1; i <= n; i++)
      sort(graph[i].begin(), graph[i].end(), greater<lli>());

    lli count = 0;
    for (i = 1; i <= n; i++) {
      Rank[i] = 1;
      Parent[i] = i;
    }

    for (i = n; i >= 1; i--) {
      auto find = [&](const auto &self, lli u) -> lli {
        return (Parent[u] == u) ? u : self(self, Parent[u]);
      };

      auto unite = [&](lli a, lli b) -> void {
        if (Rank[a] < Rank[b])
          swap(a, b);
        Rank[a] += Rank[b];
        Parent[b] = a;
        return;
      };

      ans[i] = count;
      count++;

      lli u = i;
      for (lli v : graph[u]) {
        if (v < i)
          break;
        lli x = find(find, u);
        lli y = find(find, v);
        if (x != y) {
          count--;
          unite(x, y);
        }
      }
    }

    for (i = 1; i <= n; i++)
      cout << ans[i] << "\n";
  }
  return 0;
}
