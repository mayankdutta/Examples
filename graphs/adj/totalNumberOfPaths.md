- [Total no. of paths](https://atcoder.jp/contests/abc211/tasks/abc211_d) We are required to find out the total no. of paths from 1 --> n having shortest distance. 
- Idea: just slight modification in BFS

```
  vll dist = vll(n + 1, INF);
  vll path = vll(n + 1, 0);
  queue<ll > qu;

  dist[1] = 0; 
  path[1] = 1;
  qu.push(1);

  while (!qu.empty()) {
    auto u = qu.front(); 
    qu.pop();

    for (const auto& v: graph[u]) {
      if (dist[v] == INF) {
        qu.push(v);
        dist[v] = dist[u] + 1;
        path[v] = path[u]; 
      }
      else if (dist[v] == dist[u] + 1) {
        path[v] += path[u];
        path[v] %= mod;
      }
    }
  }


```
