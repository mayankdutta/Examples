/*
 * source: https://cses.fi/problemset/task/1682/
 * Given a directed graph, we had to tell if we can reach to 
 * city B from city A, if not then report it. 
 */

#include <bits/stdc++.h>
using namespace std; 

int n, m;
vector<vector<vector<int>>> adj; /* Don't chicken out */ 
vector<bool> used;

void dfs(int n, int which) { 
    used[n] = true; 
    for (auto i: adj[n][which]) 
        if (!used[i]) 
            dfs(i, which);
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    for (auto& i: adj) i.resize(2);
    used.resize(n + 1, false); /* mistake was made here, tried to declare size m + 1, in adjacent too, hence got RTE */
    int start = INT_MAX;


    for (int i = 0; i < m; i++) { 
        int a, b;
        cin >> a >> b;

        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
        start = min(a, min(b, start));
    }

    dfs(start, 0);
    for (int i = 1; i <= n; i++) { 
        if (!used[i]) { 
            cout << "NO\n";
            cout << 1 << ' ' << i << '\n';
            return 0;
        }
    }

    for (int i = 0; i <= n; i++) used[i] = false;

    dfs(start, 1);
    for (int i = 1; i <= n; i++) { 
        if (!used[i]) { 
            cout << "NO\n";
            cout << i << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES\n";
}

/*
 * Either take two separate graph, 
 * OR 
 * make vector <int> arr[2] something like that,
 * we just need 2 graph hence this 3D vector
 * solution hint: USACO 
 */
