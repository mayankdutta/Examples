1. [Mex-Min](https://atcoder.jp/contests/abc194/tasks/abc194_e) since size is given therefore 2D array has to come to rescue. 

      ```
      void solve() {
        int n, m; cin >> n >> m;

        vvi arr(n, vi(1, 0));
        for (int i = 1; i <= n; i++) {
          int x; cin >> x;
          arr[x].push_back(i);
        }

        for (auto& i: arr)
          i.push_back(n + 1);

        /* Inserted 0 at the beginning of every sub-vector and n + 1, to the end. */

        int ans = n;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < arr[i].size() - 1; j++) {
            if (arr[i][j + 1] - arr[i][j] > m) {
              ans = min((int)i, ans);
            }
          }
        }
        cout << ans << '\n';
      }

      ```
