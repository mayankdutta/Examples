#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> dp;
int ans = 0;
int solve(const vector<int>& arr, vector<int> taken, int current) {
  ans = max(ans, (int)taken.size());

  // print(taken);
  // for (const auto& i: dp) { cout << " ( " << i.first.first << ", " << i.first.second << " ) = " << i.second << '\n'; } cout << '\n';

  if (current == arr.size())
    return (int)taken.size();

  int ans1 = solve(arr, taken, current + 1);

  if (current != -1 and
      !taken.empty() and
      dp.count(make_pair(taken.back(), current)))
    return dp[make_pair(taken.back(), current)];

  if (!taken.empty() and current >= 0 and taken.back() >= arr[current])
    return (int)taken.size();

  if (current >= 0)
    taken.push_back(arr[current]);

  int ans2 = solve(arr, taken, current + 1);
  if (current != -1) {
    dp[make_pair(taken.back(), current)] = max(ans1, ans2);
  }

  return max(ans1, ans2);
}

int main() {
  int n; cin >> n;
  vector<int> arr(n); for (auto& i: arr) cin >> i;

  vector<int> taken;
  print(taken);
  cout << solve(arr, taken, -1) << '\n';
  print(taken);
}

