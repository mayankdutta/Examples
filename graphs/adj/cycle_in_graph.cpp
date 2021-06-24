vvi adj;
vi parrent, status;

/*
 * status[i] == 0: UNVISITED
 * status[i] == 1: EXPLORED
 * status[i] == 2: VISITED
 */

int one = -1;
int two = -1;

void dfs(int u) {
  status[u] = 1;
  for (const auto& v: adj[u]) {
    if (status[v] == 0) {
      parrent[v] = u;
      dfs(v);
    }
    else if (status[v] == 1) {
      if (parrent[u] == v) { } // child parent relation
      else { // cycle, back edge
        one = u;
        two = v;
      }
    }
    else if (status[v] == 2) { // cycle, front edge. 
      one = u;
      two = v;
    }
  }
  status[u] = 2;
}

void solve() {
  int n, m;
  cin >> n >> m;

  adj = vvi(n + 1);
  parrent = vi(n + 1);
  status = vi(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  for (int i = 1; i <= n; i++) {
    if (status[i] == 0) {
      dfs(i);
    }
  }

  if (one == -1 and two == -1) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  
  vi ans;
  ans.pb(one);
  while (one != two) {
    ans.pb(two);
    two = parrent[two];
  }
  ans.pb(two);

  cout << ans.size() << '\n';
  for (const auto &i: ans) {
    cout << i << ' ';
  } cout << '\n';
}

