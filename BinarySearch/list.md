- [Number of pairs](https://codeforces.com/contest/1538/problem/C) just have to calculate, L - 1 and R then minus.<br> <br>
    ***Don't forget to use ```upper_bound and lower_bound combo``` else will confuse if we have to add ```+1``` in the end or not.
    Hence avoid U_bound, U_bound and L_bound, L_bound.*** <br><br>
    ```
      int n, l, r; cin >> n >> l >> r;
      vi arr(n); for (auto& i: arr) cin >> i;

      sort(all(arr));
      ll ans = 0;
      for (int i = 0; i < n; i++) {
        ans += upper_bound(arr.begin() + i + 1, arr.end(), r - arr[i]) -
               lower_bound(arr.begin() + i + 1, arr.end(), l - arr[i]);
      }
      cout << ans << '\n';
    ```
