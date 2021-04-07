/* 
 * Motivating problem: https://cses.fi/problemset/task/1661/
 * Differ from previous problem becuase in this we want sum EXACTLY to specific no. 
 * Not the multiple or divisible, like in previous problem. 
 */
#include <bits/stdc++.h>
using namespace std; 
using ll = long long int;

int main() { 
  ll n, x; 
  cin >> n >> x;

  vector<ll> arr(n); 
  for (auto& i: arr) 
    cin >> i;

  map<ll, ll> mp; 
  ll sum = 0;
  ll ans = 0;

  mp[0] = 1;
  for (int i = 0; i < n; i++) {
    sum += arr[i]; 

    /*
     * If there is a subarray with a prefix sum of prefix_sum - X,
     * we can exclude it from our current subarray to get the desired sum.
     * Thus, we can add the number of those subarrays to our answer.
     */

    if (mp.count(sum - x)) { 
      ans += (mp[sum - x]);
      // Increment the amount of prefix sums with a sum of prefix_sum

    }
    mp[sum] ++;
  }
  cout << ans << '\n'; 
}

