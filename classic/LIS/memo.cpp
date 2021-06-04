#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(10000, vector<int>(10000));
int solve(const vector<int>& arr, vector<int> taken, int current) {
  /*
  print(taken);
  print(arr);
  cout << '\n';
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j <= 5; j++) {
      cout << dp[i][j] << ' ';
    } cout << '\n';
  } cout << '\n';
  cout << '\n';
  */

  if (current == arr.size())
    return (int)taken.size();

  int ans1 = solve(arr, taken, current + 1);

  if (current != -1 and !taken.empty() and dp[taken.back()][current] != 0)
    return dp[taken.back()][current];

  if (!taken.empty() and current >= 0 and taken.back() > arr[current])
    return (int)taken.size();

  if (current >= 0)
    taken.push_back(arr[current]);

  int ans2 = solve(arr, taken, current + 1);
  if (current != -1)
    dp[taken.back()][current] = max(ans1, ans2);

  return max(ans1, ans2);
}

int main() {
  int n; cin >> n;
  vector<int> arr(n); for (auto& i: arr) cin >> i;

  vector<int> taken;
  cout << solve(arr, taken, -1) << '\n';
}

