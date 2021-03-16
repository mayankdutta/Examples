// Question targetted: https://cses.fi/problemset/task/1192/
// BFS was tricky somewhat then DFS

#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define Size 10000

int n, m;
char grid[Size][Size];

int dr[] = {1, -1, 0, 0}; 
int dc[] = {0, 0, -1, 1}; 

void print() { 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cout << grid[i][j] << ' '; 
        } cout << '\n';
    } cout << '\n';
}

void dfs(int r, int c) { 
    if (r < 0 or r >= n or c < 0 or c >= m) return;
    if (grid[r][c] != '.') return; 

    grid[r][c] = 'D';
    for (int i = 0; i < 4; i++) { 
        dfs(r + dr[i], c + dc[i]);
    }
}

void bfs(int r, int c) { 
    queue<ii> qu;
    qu.push({r, c});

    while (!qu.empty()) { 
        auto current = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i++) { 
            int R = current.first + dr[i]; 
            int C = current.second + dc[i]; // here too i made a mistake

            if (R < 0 or R >= n or C < 0 or C >= m) continue; 
            if (grid[R][C] != '.') continue;
            grid[R][C] = 'D'; // mistake I was making

            qu.push({R, C});
        }

    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cin >> grid[i][j];
        }
    }

    int count = 0; 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (grid[i][j] == '.') { 
                bfs(i, j); 
                // dfs(i, j);
                count ++;

                // print();
                // cout << "__ count : " << count << '\n';
                // cout << "\n\n";
            }
        }
    }
    cout << count << '\n';
}
 
/* sources
 *
 * for DFS: competitive programming 3 
 * for BFS: same and https://usaco.guide/solutions/cses-1193?lang=cpp
 */
