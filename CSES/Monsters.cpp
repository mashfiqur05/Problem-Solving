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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 1123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<int, int>> monster;
pair<int, int> st;
int n, m;
char adj[MX][MX], step[MX][MX];
bool vis[MX][MX];
string side = "DURL", ans = "";
bool f = 0;

void backtrack(int x, int y)
{
    if (step[x][y] != 'X')
    {
        char ch = step[x][y];
        ans.push_back(ch);
        if (ch == 'U')
            backtrack(x + 1, y);
        else if (ch == 'D')
            backtrack(x - 1, y);
        else if (ch == 'L')
            backtrack(x, y + 1);
        else if (ch == 'R')
            backtrack(x, y - 1);
    }
}


void bfs ()
{
    queue<pair<int, int>> q;
    for (auto u : monster)
    {
        q.push (u);
    }
    q.push (st);

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if ((cur.first == 0 || cur.first == n-1 || cur.second == 0 || cur.second == m-1) && adj[cur.first][cur.second] == 'A')
        {
            f = 1;
            backtrack (cur.first, cur.second);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int x_next = cur.first + dx[i];
            int y_next = cur.second + dy[i];

            if (adj[x_next][y_next] != '.' || x_next < 0 || x_next == n || y_next < 0 || y_next == m) continue;
            adj[x_next][y_next] = adj[cur.first][cur.second];

            if (adj[x_next][y_next] == 'A')
            {
                step[x_next][y_next] = side[i];
            }

            q.push ({x_next, y_next});
        }
    }
}


void solve (int testCase)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == 'M') monster.push_back ({i, j});
            if (adj[i][j] == 'A') st = {i, j};
        }
    }
    step[st.first][st.second] = 'X';

    bfs ();
    if (f) 
    {
        cout << "YES" << endl;
        reverse (all (ans));
        cout << ans.size() << endl << ans << endl;
    }
    else cout << "NO" << endl;
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