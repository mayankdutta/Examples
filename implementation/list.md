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
       odd  += (node.ss)%2;  // remainder will always be 1 if node.ss is odd
       even += (node.ss)/2; // will always be 1 if node.ss is even
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
      #include <iostream>
      #include <vector>
      #include <cmath>
      #include <ctime>
      #include <cassert>
      #include <cstdio>
      #include <queue>
      #include <set>
      #include <map>
      #include <fstream>
      #include <cstdlib>
      #include <string>
      #include <cstring>
      #include <algorithm>
      #include <numeric>

      #define mp make_pair
      #define mt make_tuple
      #define fi first
      #define se second
      #define pb push_back
      #define all(x) (x).begin(), (x).end()
      #define rall(x) (x).rbegin(), (x).rend()
      #define forn(i, n) for (int i = 0; i < (int)(n); ++i)
      #define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
      #define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
      #define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

      using namespace std;

      typedef pair<int, int> pii;
      typedef vector<int> vi;
      typedef vector<pii> vpi;
      typedef vector<vi> vvi;
      typedef long long i64;
      typedef vector<i64> vi64;
      typedef vector<vi64> vvi64;

      template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
      template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

      int main() {
         ios::sync_with_stdio(false);
         cin.tie(nullptr);
         cout.precision(10);
         cout << fixed;

         #ifdef LOCAL_DEFINE
         freopen("input.txt", "rt", stdin);
         #endif

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
         #ifdef LOCAL_DEFINE
         cerr << "Time elapsed: " << 1.0 \* clock() / CLOCKS_PER_SEC << " s.\n";
         #endif
         return 0;
      }
   ```
