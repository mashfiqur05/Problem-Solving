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

char grid[25][25];
int dis[25][25];
bool vis[25][25];
int h, w;
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs (int sr, int sc)
{
    mem(vis, false);
    mem(dis, 0);

    queue<pair<int, int>> q;
    q.push ({sr, sc});
    vis[sr][sc] = true;
    dis[sr][sc] = 0;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        for (auto option : path)
        {
            int cx = p.first + option.first;
            int cy = p.second + option.second;

            if (cx >= 0 && cx < h && cy >= 0 && cy < w && grid[cx][cy] != '#' && !vis[cx][cy])
            {
                q.push ({cx, cy});
                vis[cx][cy] = true;
                dis[cx][cy] = dis[p.first][p.second] + 1;
            }
        }
    }
}

void solve ()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    int ans = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.')
            {
                bfs (i, j);

                for (int x = 0; x < h; x++)
                    for (int y = 0; y < w; y++)
                        ans = max (ans, dis[x][y]);
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}