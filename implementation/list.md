1. yet another short trick for counting even and odd.

   ```
   string s;
   cin >> s;
   int even =0 ;
   int odd = 0;
   map<char,int> cnt;
   for(auto node : s)
       cnt[node]++;
   for(auto node : cnt) {
       odd  += (node.ss) % 2;  // remainder will always be 1 if node.ss is odd
       even += (node.ss) / 2; // will always be 1 if node.ss is even
   }


   ```

2. string to functions

   ```
   #define forn(i, n) for (int i = 0; i < int(n); i++)

   vector<pair<char,int>> split(string s) {
      char c = s[0];
      int cnt = 1;
      vector<pair<char,int>> result;
      auto ss = s.c_str();
      for (int i = 1; i <= int(s.length()); i++) {
         if (ss[i] != c) {
            result.push_back({c, cnt});
            c = s[i];
            cnt = 1;
         } else
            cnt++;
      }
      return result;
   }

   int main() {
      int n;
      cin >> n;
      forn(tt, n) {
         string s, t;
         cin >> s >> t;
         auto sa(split(s)), ta(split(t)); //line of focus
         bool ok = sa.size() == ta.size();
         if (ok)
            forn(i, sa.size())
                  if (sa[i].first != ta[i].first || sa[i].second > ta[i].second)
                     ok = false;
         cout << (ok ? "YES" : "NO") << endl;
      }
   }

   ```

3. taking input

   ```
   int h, m;
   scanf("%d:%d", &h, &m);

   /* input was of this type
    * 12:21
    */

   while (1) {
      m++;
      if (m == 60) {
         m = 0;
         h = (h + 1) % 24;
      }
      if ((m%10 == h/10) && (h%10 == m/10)) {
         printf("%02d:%02d",h,m);
         return 0;
      }
   }

   ```

4. [Ternary things](//https://codeforces.com/contest/755/problem/B)

   ```
      //https://codeforces.com/contest/755/problem/B
      //can also be used in set
      int main() {
         int n, m;
         cin >> n >> m;
         set<string> s, t;
         forn(i, n + m) {
            string x;
            cin >> x;
            (i < n ? s : t).insert(x);
         }

         int a = 0, b = 0, c = 0;
         for (auto w: s) {
            if (t.count(w)) ++c;
            else ++a;
         }

         b = m - c;
         int pl = 0;
         while (a + c) {
            if (c) --c;
            else --a;
            swap(a, b);
            pl ^= 1;
         }
         cout << (pl ? "YES" : "NO") << '\n';
      }
   ```
5. [C - Reorder Cards](https://atcoder.jp/contests/abc213/tasks/abc213_c)
   Problem required the concept of **Coordinate Compression** hence new approach to me. 
   
   ```   
     ll h, w, n;
     cin >> h >> w >> n;

     vector<int> arr, brr;
     for (int i = 0; i < n; i++) {
       int a, b;
       cin >> a >> b;

       arr.pb(a);
       brr.pb(b);
     }

     auto row = arr;
     auto col = brr;

     sort(all(row));
     sort(all(col));

     row.resize(unique(all(row)) - row.begin());
     col.resize(unique(all(col)) - col.begin());

     for (int i = 0; i < n; i++) {
       int a = lower_bound(all(row), arr[i]) - row.begin() + 1;
       int b = lower_bound(all(col), brr[i]) - col.begin() + 1;

       cout << a << ' ' << b << '\n';
     }
   ```
