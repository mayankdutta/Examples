// https://atcoder.jp/contests/abc225/tasks/abc225_d
// see this implmentation, kind of LL 
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> prev(n + 1, -1), next(n + 1, -1);
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1 or type == 2) {
      int a, b;
      cin >> a >> b;

      if (type == 1) {
        next[a] = b;
        prev[b] = a;
      } else {
        next[a] = -1;
        prev[b] = -1;
      }
    } else {
      int x;
      cin >> x;
      vector<int> ans;

      auto temp = x;
      while (prev[temp] != -1) {
        temp = prev[temp];
        ans.push_back(temp);
      }

      reverse(ans.begin(), ans.end());
      ans.push_back(x);
      temp = x;

      while (next[temp] != -1) {
        temp = next[temp];
        ans.push_back(temp);
      }

      cout << ans.size() << ' ';
      for (const auto &i : ans)
        cout << i << ' ';
      cout << '\n';
    }
  }
}
