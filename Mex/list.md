1. [Mex-Min](https://atcoder.jp/contests/abc194/tasks/abc194_e) since size is given therefore 2D array has to come to rescue. 

      ```
      void solve() {
        int n, m; cin >> n >> m;

        vvi arr(n, vi(1, 0));
        for (int i = 1; i <= n; i++) {
          int x; cin >> x;
          arr[x].push_back(i);
        }

        for (auto& i: arr)
          i.push_back(n + 1);

        /* Inserted 0 at the beginning of every sub-vector and n + 1, to the end. */

        int ans = n;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < arr[i].size() - 1; j++) {
            if (arr[i][j + 1] - arr[i][j] > m) {
              ans = min((int)i, ans);
            }
          }
        }
        cout << ans << '\n';
      }

      ```
2. Encountered a leetcode question did with some another approach. 
      ```
           int firstMissingPositive(vector<int>& nums) {

            vector<int> arr;

            for (int i = 0; i< nums.size(); i++) if (nums[i] > 0) arr.push_back(nums[i]);

            if (arr.empty()) return 1; 

            sort(arr.begin(), arr.end());

            int n = arr.size();
            if ( arr.front() > 1) return 1;

            /* could have done without using this */ 
            n = unique(arr.begin(), arr.end()) - arr.begin(); 
            arr.resize(n);

            for (int i = 1; i< n; i++) if (arr[i] - arr[i - 1] > 1) return arr[i - 1] + 1; 
                
            return arr.back() + 1;
        }
      ```
