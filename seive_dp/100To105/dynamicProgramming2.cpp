#include <bits/stdc++.h>
using ll = long long int;
using namespace std; 
#define rep(i, a, n) for (ll i = a; i < n; i++) 
#define Size 100000

int main () { 
  ll x;
  cin >> x; 

  vector<int> dp(Size, 0);
  dp[0] = 1;
  for (int i = 0; i < 100000; i++) { 
    if (dp[i]) { 
      dp[i + 100] = 1; 
      dp[i + 101] = 1; 
      dp[i + 102] = 1; 
      dp[i + 103] = 1; 
      dp[i + 104] = 1; 
      dp[i + 105] = 1; 
    }
  }

  cout << (dp[x] ? "1\n" : "0\n");
}
