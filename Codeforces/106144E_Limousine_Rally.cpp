///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
// #define int long long
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

int ans = 0;
vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j, int n, int m, int k, vector<string> &grid, vector<vector<int>> &khali, vector<vector<bool>> &vis)
{
    if (i >= 0 && i < n && j >= 0 && j < m && khali[i][j] >= k && !vis[i][j]) return true;
    else return false;
}

void bfs (int n, int m, int k, vector<string> &grid, vector<vector<int>> &khali, vector<vector<bool>> &vis)
{
    queue<pair<int, int>> q;
    if (khali[0][0] >= k)
    {
        q.push({0, 0});
        vis[0][0] = true;
        ans = k;
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        int x = u.first, y = u.second;
        vis[x][y] = true;

        for (auto d : dir)
        {
            int nx = x + d.first, ny = y + d.second;
            if (isValid(nx, ny, n, m, k, grid, khali, vis)) 
            {
                q.push ({nx, ny});
                ans = max (ans, nx + k);
                vis[nx][ny] = true;
            }
        }
    }
}

void solve (int CaseNo)
{
    int n, m, k; cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> khali(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int j = 0; j < m; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (grid[i][j] == '.')
                khali[i][j] = 1 + (i + 1 < n ? khali[i + 1][j] : 0);
            else
                khali[i][j] = 0;
        }
    }

    if (khali[0][0] < k)
    {
        cout << 0 << endl;
        return;
    }

    ans = k;
    bfs (n, m, k, grid, khali, vis);

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}