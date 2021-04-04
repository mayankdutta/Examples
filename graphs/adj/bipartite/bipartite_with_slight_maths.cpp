/*
 * Motivational problem: https://codeforces.com/contest/862/problem/B
 * source: usaco 
 * Topic: Bipariteness + maths
 * Failed miserably in maths part, done graph part though
 */

#include <bits/stdc++.h>
using namespace std; 
using ll = long long int;


vector<set<int>> adj;
vector<bool> used;
vector<bool> color;
bool good = true; 

void dfs(int n, bool current = true) {
  used[n] = true; 
  color[n] = current; 

  for (const auto& i: adj[n]) { 
    if (used[i]) { 
      if (color[i] == current) { 
        good &= (color[i] != current);
      }
    }
    else { 
      dfs(i, !current); 
    }
  }
}

int main() { 
  int n; 
  cin >> n; 

  adj.resize(n + 1); 
  used.resize(n + 1, false);
  color.resize(n + 1, false);

  for (int i = 0; i < n - 1; i++) { 
    int a, b; 
    cin >> a >> b;

    adj[a].insert(b); 
    adj[b].insert(a);
  }

  for (int i = 1; i <= n; i++)  
    if (!used[i]) 
      dfs(i);

  vector<int> arrOne, arrTwo;
  for (int i = 1; i <= n; i++) { 
    if (color[i]) arrOne.push_back(i);
    else arrTwo.push_back(i);
  }

  ll ans = (ll)arrOne.size(); 
  ans *= (ll)arrTwo.size(); 
  ans -= (n - 1);

  cout << ans << '\n';
}

