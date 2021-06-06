int lengthOfLIS(vector<int>& nums) {
  int ans = 0;
  multiset<int> st;
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    auto it = st.lower_bound(nums[i]);
    if (it == st.end()) st.insert(nums[i]);
    else {
      st.erase(it);
      st.insert(nums[i]);
    }
  }
  return st.size();
}
