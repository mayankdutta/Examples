1. [AquaMoon and Stolen String](https://codeforces.com/contest/1546/problem/B) <br>
    The solution for B can be found with XOR since every element except for only one is appeared in even number of time. 
    Their XOR will be 0 and the odd one out will be revealed. 
    
    ```
    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    string ans;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    ans = arr.front();
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[j] = ans[j] ^ arr[i][j];
      }
    }

    for (int i = 0; i < n - 1; i++) {
      string s;
      cin >> s;

      for (int j = 0; j < m; j++) {
        ans[j] = ans[j] ^ s[j];
      }
    }
    cout << ans << endl;

    ```

