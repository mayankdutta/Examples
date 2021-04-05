/* 
 * Topic: prefix sum, number theory  
 * Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=595
 *
 */

#include <bits/stdc++.h>
using namespace std; 

void solve() {
    int n; 
    cin >> n; 
    vector<int> arr(n); 
    for (auto& i: arr) cin >> i;

    int num = 7;
    vector<int> prefix; 
    prefix.push_back(arr.front()); 
    for (int i = 1; i < n; i++) { 
        prefix.push_back(prefix.back() + arr[i]); 
        prefix[i] %= num; /* very important approach */
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < prefix.size(); i++)  /* what remaining was to find the diff of the index, of repeating characters */
        mp[prefix[i]].push_back(i); /* If some other method, then please update */

    int ans = 0; 
    for (const auto& i: mp)  
        ans = max(ans, i.second.back() - i.second.front());
    cout << ans << '\n';
}

int main() { 
    int t = 1;
    while (t--) 
        solve(); 
}

