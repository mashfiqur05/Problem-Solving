///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve ()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(m+1, 0));
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
            mx = max(mx, adj[i][j]);
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (adj[i][j] == mx)
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    int ans = 0;
    /*
    1 2 3
    4 5 6
    7 8 9

    (-1, 0) (1, 0) (0, -1) (0, 1)
    (-1, -1) (-1, 1) (1, -1) (1, 1)
    */
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            ans = max(ans, dist[nx][ny]);

            q.push({nx, ny});
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}