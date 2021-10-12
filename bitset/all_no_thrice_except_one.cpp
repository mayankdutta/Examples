// https://leetcode.com/problems/single-number-ii/

int singleNumber(vector<int>& nums) {
  vector<int> arr(64, 0);
  for (const auto& num: nums) {
    for (int j = 0; j < 32; j++) {
      if (num >> j & 1) { // bought any value @jth position to first and then taken & with one.
        arr[j] ++;
      }
    }
  }

  long long int ans = 0;
  for (auto& a: arr)  a %= 3;

  for (int i = 0; i < 33; i++) 
    ans += arr[i] * pow(2, i);

  return ans;
}
