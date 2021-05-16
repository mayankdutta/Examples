/* 
 * New approach to me, but crux was prefix sum
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int test;
  cin >> test;

  while (test--) {
    int n;    cin >> n;
    string s; cin >> s;

    /*
     * Prefix to keep track of the sheep prior to index 'i', to be moved at index 'i'
     * Suffix to ________________________after ___________________________________'i'
     *
     */
    vector<ll> prefix(n + 1, 0);
    /* n + 2, kind of necessary to prevent seg. fault */
    vector<ll> suffix(n + 2, 0);

    ll sheep = 0; // to create track of sheep at every index, kind of prefix sum
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '*') sheep ++, prefix[i] = prefix[i - 1];
      else prefix[i] = prefix[i - 1] + sheep;
    }

    sheep = 0;
    for (int i = n; i >= 1; i--) {
      if (s[i - 1] == '*') sheep ++, suffix[i] = suffix[i + 1];
      else suffix[i] = suffix[i + 1] + sheep;
    }

    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
      ans = min(ans, prefix[i] + suffix[i]);
    cout << ans << '\n';
  }
}

/*
problem: https://codeforces.com/contest/1520/problem/E
similar problem: https://atcoder.jp/contests/abc102/tasks/arc100_a
solutions: https://codeforces.com/submissions/JustNik77/page/2
           https://codeforces.com/contest/1520/submission/115315773

text that may help:
My DP solution for E: we can find all pref[i] values where pref[i] shows how many moves we need to move all sheep to the left from i to i.
If a sheep doesn't stay at i position, then pref[i] = pref[i ‚Äî 1] + was ( was is an amount of sheep to the left from i),
else pref[i] = pref[i ‚Äî 1]. Same operations we can do for suff (we go from n to 1).
Then we can simply check for every i: ans = min(ans, pref[i] + suff[i + 1]).
*/
