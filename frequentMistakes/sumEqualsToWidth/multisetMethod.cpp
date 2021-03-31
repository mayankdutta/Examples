/*
 * Problem appeared in cf: https://codeforces.com/contest/1498/problem/B
 * Before that, seen in multiple places, but had no perfectly working sol.
 * Well gladly, now we have one...
 * Problem was required to find minimum height
 * that can be raised, by optimillay fitting some boxes
 * of certain width,
 * in a given WIDTH
 */

#include <bits/stdc++.h>
using namespace std; 
#define rep(i, a, n) for (int i = a; i < n; i++) 

void solve() { 
    int N, W;
    cin >> N >> W;

    multiset<int> st;
    rep(i, 0, N) { 
        int num; 
        cin >> num;
        st.insert(num);
    }

    int height = 1; 
    int temp = W;

    while (!st.empty()) {  /* This method somehow works, */
        auto it = st.lower_bound(temp + 1); 
        if (it == st.begin()) { 
            temp = W; 
            height ++; 
            continue;
        }

        -- it; 
        temp -= *it;
        st.erase(it);
    }

    cout << height << '\n';
}

int main() { 
    int t = 1;
    cin >> t;
    while (t--) 
        solve(); 
}

