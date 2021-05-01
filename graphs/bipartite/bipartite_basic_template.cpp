/*
 * Bipartite, divide neighbours such that no neighbouring element should have same colour.
 * Motivation problem: https://cses.fi/problemset/task/1668/
 * Solution guide: https://usaco.guide/silver/dfs?lang=cpp
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = long long int;

int n, m; 
vector<vector<int>> adj;
vector<bool> color;  /* just one extra thing */
vector<bool> used; 
bool good = true; 

void dfs(int v, bool current = false) { 
  used[v] = true; 
  color[v] = current;
  for (auto u: adj[v]) { 

    if (used[u]) { 
      if (color[u] == current) 
        good &= (color[u] != current); /* once good is false, always will be false, means impossible */
    }
    else dfs(u, !current); 
  }
}

int main() { 
  cin >> n >> m;

  adj.resize(n + 1); 
  used.resize(n + 1, false); 
  color.resize(n + 1, false);

  for (int i = 0; i < m; i++) { 
    int a, b; 
    cin >> a >> b;
    adj[a].push_back(b); 
    adj[b].push_back(a); 
  }

  for (int i = 1; i <= n; i++) {  /* This step was also quite important, reason sadly still unknown, maybe for disconnected graph */
    if (!used[i])  
      dfs(i); 
  }

  if (!good) { 
    cout << "IMPOSSIBLE\n"; 
  }

  else { 
    for (int i = 1; i <= n; i++) { 
      cout << (color[i] ? 1 : 2) << ' '; 
    }
  }
}

