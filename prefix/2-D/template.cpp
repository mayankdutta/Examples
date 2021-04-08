/*
 * Topic: 2-D prefix
 * Motivation problem: https://cses.fi/problemset/task/1652/
 * Read the comments carefully
 */

#include <iostream>
using ll = long long int;
#define rep(i, a, n) for (ll i = a; i < n; i++)

int main() { 
  ll n, queries;
  std::cin >> n >> queries;

  char grid[n][n]; 
  ll prefix[n + 1][n + 1];

  rep(i, 0, n) rep(j, 0, n) std::cin >> grid[i][j];
  rep(i, 0, n + 1) rep(j, 0, n + 1) prefix[i][j] = 0;

  /* indexing of prefix and grid are different, one is 1-based and latter is 0-based */
  rep(i, 1, n + 1) rep (j, 1, n + 1) prefix[i][j] = (grid[i - 1][j - 1] == '*')  // Carefull with the indexing
    + prefix[i - 1][j] 
    + prefix[i][j - 1] 
    - prefix[i - 1][j - 1];

  while (queries --) { 
    int x1, y1, x2, y2; 
    std::cin >> x1 >> y1 >> x2 >> y2;

    /* no need to subtract one from x1, x2 and all, because prefix is already 1 - based index */

    std::cout << prefix[x2][y2] 
      - prefix[x1 - 1][y2] 
      - prefix[x2][y1 - 1] 
      + prefix[x1 - 1][y1 - 1] <<'\n';
  }
}

 
