#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& arr, vector<int> taken, int current) {
  if (current == arr.size())
    return (int)taken.size();

  int ans1 = solve(arr, taken, current + 1);

  if (!taken.empty() and current >= 0 and taken.back() > arr[current])
    return (int)taken.size();

  if (current >= 0)
    taken.push_back(arr[current]);

  int ans2 = solve(arr, taken, current + 1);
  return max(ans1, ans2);
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  vector<int> taken;

  for (auto& i: arr) cin >> i;
  cout << solve(arr, taken, -1) << '\n';
}

