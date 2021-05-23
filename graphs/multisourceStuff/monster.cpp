#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
using lld=long double;

#define mp make_pair
#define pb push_back
#define accu accumulate

#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>

#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>

#define pii pair<int, int>
#define fast std::ios_base::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

#define rep(i, a, n) for (ll i = a; i < n; i++)
#define all(c) (c).begin(), (c).end()

void solve() {
    int n, m;
    cin >> n >> m;

    vvc grid(n, vc(m));
    vvb used(n, vb(m, false));
    vvi dist_man(n, vi(m, -1)), dist_monster(n, vi(m, 10000));
    vvi traceback(n, vi(m, 0));

    vector<pii> dot;
    vector<pii> monster;
    pii man;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, 1, -1};
    string paths = "UDRL";

    rep(i, 0, n) rep(j, 0, m) {
        cin >> grid[i][j];

        if (grid[i][j] == 'A') man = {i, j};
        if (grid[i][j] == 'M') monster.push_back({i, j});
        if (grid[i][j] == '.' or grid[i][j] == 'A') if (i == 0 or i == n - 1 or j == 0 or j == m - 1) dot.push_back({i, j});
    }

    queue<pii> qu;
    qu.push({man.first, man.second});
    used[man.first][man.second]     = true;
    dist_man[man.first][man.second] = 0;

    while(!qu.empty()) {
        auto [r, c] = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i++) {
            int rr = dr[i] + r;
            int cc = dc[i] + c;

            if (rr < 0 or cc < 0 or rr >= n or cc >= m) continue;
            if (grid[rr][cc] == '#') continue;
            if (used[rr][cc]) continue;
            if (grid[rr][cc] == 'M') continue;

            dist_man[rr][cc] = dist_man[r][c] + 1;
            qu.push({rr, cc});
            used[rr][cc] = true;
            traceback[rr][cc] = i;

        }
    }

    queue<pii> temp;
    swap(temp, qu);
    used = vvb(n, vb(m, false));
    for (const auto& i: monster) {
        qu.push({i.first, i.second});
        dist_monster[i.first][i.second] = 0;
        used[i.first][i.second] = true;
    }

    while(!qu.empty()) {
        auto [r, c] = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i++) {
            int rr = dr[i] + r;
            int cc = dc[i] + c;

            if (rr < 0 or cc < 0 or rr >= n or cc >= m) continue;
            if (grid[rr][cc] == '#') continue;
            if (used[rr][cc]) continue;

            dist_monster[rr][cc] = dist_monster[r][c] + 1;
            qu.push({rr, cc});
            used[rr][cc] = true;
        }
    }

    /*
    for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { cout << grid[i][j] << ' '; } cout << '\n'; } cout << '\n';
    for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { cout << dist_man[i][j] << ' '; } cout << '\n'; } cout << "\n\n";
    for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { cout << dist_monster[i][j] << ' '; } cout << '\n'; } cout << "\n\n";
    for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) { cout << traceback[i][j] << ' '; } cout << '\n'; } cout << "\n\n";
    */

    bool good = false;
    pii destination;

    for (const auto& i: dot) {
        if (dist_man[i.first][i.second] != -1 and dist_man[i.first][i.second] < dist_monster[i.first][i.second]) {
            good = true;
            destination = {i.first, i.second};
            break;
        }
    }


    if (!good) {
        cout << "NO\n";
        return;
    }

    string ans;
     // debug4(man.first, man.second, destination.first, destination.second);

    while (man != destination) {
        auto now = traceback[destination.first][destination.second];
        ans.push_back(paths[now]);
        destination = {destination.first - dr[now], destination.second - dc[now]};

     // debug4(man.first, man.second, destination.first, destination.second);

        // debug(ans);
    }
    reverse(all(ans));
    cout << "YES\n";
    cout << ans.size() << '\n';
    cout << ans << '\n';
}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
