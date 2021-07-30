# Prefix sums 

1. Prefix sums GCD except one digit, [Blackboard GCD](https://atcoder.jp/contests/abc125/tasks/abc125_c)
2. Prefix sums + NT just like blackboard GCD, [Orac and LCM](https://codeforces.com/contest/1349/problem/A)
3. given an array requirement is to find the prefix of every index. [Task](https://codeforces.com/contest/1539/problem/B)

    ```
      int n; cin >> n;
        int q; cin >> q;
        string s;
        cin >> s;

        vvi hash(n + 1, vi(27, 0));
        for (int i = 0; i < n; i++) {
            hash[i][s[i] - 'a'] ++;
            if (i != 0) {
                for (int j = 0; j < 27; j++) {
                    hash[i][j] += hash[i - 1][j];
                }
            }
        }

        while (q --) {
            int l, r; cin >> l >> r;
            l --, r --;

            ll ans = 0;
            for (ll i = 0; i < 27; i++) {
                ll one = 0;
                if (l > 0) one = hash[r][i] - hash[l - 1][i];
                else one = hash[r][i];
                ans += (one) * (i + 1);
            }
            cout << ans << '\n';
        }
    ```
4. [Yet another problem](https://codeforces.com/contest/1555/problem/C) unsolved though.
