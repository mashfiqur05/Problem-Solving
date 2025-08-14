///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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
const int MX = 1123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<pair<int, int>> path = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m, k, vis[MX][MX], cnt = 0;
char grid[MX][MX];
map<pair<int, int>, int> pictures_cnt;
vector<pair<int, int>> ind;

void dfs (int x, int y)
{
    vis[x][y] = 1;
    ind.push_back ({x, y});
    for (auto u : path)
    {
        int c_x = x + u.first, c_y = y + u.second;
        if (grid[c_x][c_y] == '*') cnt++;
        else if (vis[c_x][c_y] == 0) dfs (c_x, c_y);
    }
}

void solve (int CaseNo)
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> grid[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) 
        {
            if (vis[i][j] == 0 && grid[i][j] == '.')
            {
                cnt = 0; ind.clear();
                dfs (i, j);
                for (auto u : ind) 
                {
                    pictures_cnt[{u.first, u.second}] = cnt;
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        cout << pictures_cnt[{x, y}] << endl;
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}