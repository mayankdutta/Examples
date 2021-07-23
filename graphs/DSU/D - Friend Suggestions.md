- Technique of DSU and slight graph was involved. 
- [D - Friend Suggestions](https://atcoder.jp/contests/abc157/tasks/abc157_d) Take special care during calculating the size of the DSU.

```

#include<bits/stdc++.h>
using namespace std; 

class UnionSet {
	public: 
		vector<int> parent; 
		vector<int> rank; 
		vector<int> Size;

		UnionSet(int n) {
			parent.resize(n + 1, 0); 
			rank.resize(n + 1, 0);
			Size.resize(n + 1, 1);

			for (int i = 1; i <= n; i++) parent[i] = i;
		}

		bool isSame(int a, int b) {
			return find(a) == find(b); 
		}
		int find(int n) {
			return (n == parent[n] ? n : parent[n] = find(parent[n]));
		}

		void merge(int i, int j) {
			if (!isSame (i, j)) {
				int x = find (i), y = find (j);
				if (rank [x] > rank[y]) {
					parent[y] = x;
					Size[x] += Size[y];
				}
				else {
					parent[x] = y;
					if (rank [x] == rank[y]) rank [y] ++;
					Size[y]+= Size[x];
				}
			}
		}
		int getSize(int n) {
		    return Size[find(n)];
		}
};

int main() {
	int n, m, k; 
	cin >> n >> m >> k;

	vector<vector<int>> arr(n + 1); 

	UnionSet dsu(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b); 
		arr[b].push_back(a);

		dsu.merge(a, b);
	}

	vector<int> ans(n + 1, 0);
	for (int i = 1; i <= n; i++) {	    
    /* Adding all related friends subtracting direct friend and subtracting himself. */
		ans[i] = (dsu.getSize(i) - arr[i].size() -1);
	}
	
	for (int i = 0; i < k; i++) {
		int a, b; 
		cin >> a >> b; 

		if (dsu.isSame(a, b)) {
			ans[a] --; 
			ans[b] --; 
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans [i] << ' '; 
	}
}

```
