## Floyd warshall template

#### Predefined
```
#define ll long long int
#define vll vector<long long int>
#define vvll vector<vector<long long int>>
```

#### Main code
```
  int n, m, q;
  cin >> n >> m >> q;

  vvll grid = vvll(n, vll(n, INF));
  for (int i = 1; i <= m; i++) {
    ll a, b, w;
    cin >> a >> b >> w;
    a--, b--;                           /* Make everything to 0 indexed */
    grid[a][b] = min(w, grid[a][b]);    /* Must to avoid self loop of heavier weights. */
    grid[b][a] = min(w, grid[b][a]);
  }

  for (int i = 0; i < n; i++) {         /* This is an also important step */
    grid[i][i] = 0;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
      }
    }
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;                           /* To make everything into 0 indexed array */
    if (grid[a][b] == INF) {
      cout << "-1\n";
    } else {
      cout << grid[a][b] << '\n';
    }
  }

```
