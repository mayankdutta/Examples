
* Motivating problem: https://codeforces.com/problemset/problem/20/C
* implemented the most basic dijsktra
* implementation method was using priority queue


```
  #define vll vector<long long int>
  using ll = long long int;
  
  vector<vector<pll>> adj = vector<vector<pll>>(n + 1);
  for (int i = 0; i < m; i++) {
    ll a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  int s = 1; /* source */
  vll dist(n + 1, INF);
  vll path(n + 1, INF);
  dist[s] = 0;
```

Implementation stuff. 
```
  priority_queue<pll, vector<pll>, greater<pll>> pq;

  pq.push({0, s});
  
  /* Format is (distance, vertex) */
  
  while (!pq.empty()) {
    auto front = pq.top();
    pq.pop();
    ll d = front.first;
    ll u = front.second;

    if (d > dist[u])
      continue; // trying to understand this

    for (const auto &v : adj[u]) {
      /*
         take v.first as 'to'
         u as 'from'
       */
      if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second;
        pq.push({dist[v.first], v.first});
        path[v.first] = u;
      }
    }
  }
```

Tracking  shortest path. 
```
  vll ans;
  for (int i = n; i != 1; i = path[i])
    ans.push_back(i);
  ans.push_back(1);

  reverse(all(ans));

```
