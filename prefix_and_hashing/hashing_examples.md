1. [AquaMoon and Stolen String](https://codeforces.com/contest/1546/problem/B) <br>
   ```
    int n, m;     cin >> n >> m;

    vector<vector<int>> hashing(m, vector<int>(26));
    for (int i = 0; i < n; i++) {
      string s;      cin >> s;
      
      for (int j = 0; j < m; j++) 
        hashing[j][s[j] - 'a']++;      
    }

    for (int i = 0; i < n - 1; i++) {
      string s;      cin >> s;
      
      for (int j = 0; j < m; j++) 
        hashing[j][s[j] - 'a']--;
    }

    for (int i = 0; i < m; i++) 
      for (int j = 0; j < 26; j++) 
        if (hashing[i][j]) 
          cout << (char)(j + 'a');

    cout << '\n';

   ```
