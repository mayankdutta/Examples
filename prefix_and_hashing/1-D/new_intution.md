[525. Contiguous Array](https://leetcode.com/problems/contiguous-array/) <br><br>
[graph paper type approach](https://leetcode.com/problems/contiguous-array/discuss/99655/Python-O(n)-Solution-with-Visual-Explanation)

### Try plotting values of count wrt index(1-index base) on graph paper. 
```cpp
      int n = nums.size(); 
        
        map<int, int> mp; 
        int count = 0; 
        
        int ans = 0;
        mp[0] = 0;
        for (int i= 0; i < n; i++) {
            nums[i] == 0 ? count -- : count ++;
            
            if (mp.count(count)) {
                ans = max(ans, i + 1 - mp[count]);
            }
            else {
                mp[count] = i + 1;
            }
        }
        
        return ans;
        
```
