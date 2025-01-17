///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// BFS Function
int bfs(pair<int, int> start, pair<int, int> h, vector<vector<char>>& g, int n, int m) {
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, 0));

    q.push(start);
    vis[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int cur_x = cur.first;
        int cur_y = cur.second;

        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m &&
                g[next_x][next_y] != '#' && g[next_x][next_y] != 'm' &&
                !vis[next_x][next_y]) {

                vis[next_x][next_y] = true;
                dis[next_x][next_y] = dis[cur_x][cur_y] + 1;
                q.push({next_x, next_y});
            }
        }
    }
    return dis[h.first][h.second];
}

// Solve Function
void solve(int testCase) {
    cout << "Case " << testCase << ": ";
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    pair<int, int> a, b, c, h;

    // Input grid and locate positions of a, b, c, and h
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'a') a = {i, j};
            if (g[i][j] == 'b') b = {i, j};
            if (g[i][j] == 'c') c = {i, j};
            if (g[i][j] == 'h') h = {i, j};
        }
    }

    // Compute the maximum distance to h from a, b, and c
    int ans = bfs(a, h, g, n, m);
    ans = max(ans, bfs(b, h, g, n, m));
    ans = max(ans, bfs(c, h, g, n, m));

    cout << ans << endl;
}

int32_t main() {
    fastio();

    int testcases;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++) {
        solve(tt);
    }

    return 0;
}
