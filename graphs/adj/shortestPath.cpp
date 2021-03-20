// Learning source: https://cp-algorithms.com/graph/breadth-first-search.html
// motivating problem: https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
using namespace std; 
using ll = long long int;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<bool> used(n + 1, false); 
  vector<int> d(n + 1, 0);
  vector<int> p(n + 1, 0);

  for (int i = 0; i < m; i++) { 
    int a, b; 
    cin >> a >> b;
    adj[a].push_back(b); 
    adj[b].push_back(a);
  }

  queue<int> q; 
  q.push(1); 
  used[1] = true; 
  d[1] = 0; 
  p[1] = -1; 


  while (!q.empty()) { 
    int current = q.front(); 
    q.pop(); 

    for (const auto& i: adj[current]) { 
      if (!used[i]) { 
        used[i] = true; 
        q.push(i); 
        d[i] = d[current] + 1; 
        p[i] = current; 
      }
    }
  }

  if (!used[n]) { 
    cout << "IMPOSSIBLE\n";
  }
  else {
    vector<int> paths; 
    for (int i = n; i != -1; i = p[i]) { 
      paths.push_back(i);
    }
    reverse(paths.begin(), paths.end());
    cout << paths.size() << '\n';
    for (const auto& i: paths) { 
      cout << i << ' ';
    } cout << '\n';
  }
}

