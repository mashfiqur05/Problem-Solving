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
const int N = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

/*
..B....x
.x.xx...

..x.x.x.x
x..B.B..x
..x.x.x.x
x.xb...x

*/
int n;
char s[2][N];
bool vis[2][N];

void bfs (int x, int y)
{
    queue<pair<int, int>> q;
    q.push ({x, y});
    vis[x][y] = true;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        int i = u.first, j = u.second;
        // cout << i << " " << j << endl;
        if (i+1 < 2 && !vis[i+1][j] && s[i+1][j] == '.')
        {
            q.push({i+1, j});
            vis[i+1][j] = true;
        }
        if (i-1 >= 0 && !vis[i-1][j] && s[i-1][j] == '.')
        {
            q.push ({i-1, j});
            vis[i-1][j] = true;
        }
        if (j+1 < n && !vis[i][j+1] && s[i][j+1] == '.')
        {
            q.push ({i, j+1});
            // cout << i << " " << j+1 << endl;
            // cout << q.empty() << endl;
            vis[i][j+1] = true;
        }
    }
}

void solve ()
{
    mem (vis, false);
    memset(s, 0, sizeof(s));
    cin >> n;
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s[i][j];
        }
    }
    
    string s1, s2;
    for (int i = 0; i < n; i++)
    {
        s1 += s[0][i];
        s2 += s[1][i];
    }
    vector<int> left(n, 0), right(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0) left[i] = (s1[i] == '.' || s2[i] == '.');
        else left[i] = left[i-1] + (s1[i] == '.' || s2[i] == '.');
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (i == n-1) right[i] = (s1[i] == '.' || s2[i] == '.');
        else right[i] = right[i+1] + (s1[i] == '.' || s2[i] == '.');
    }

    int region = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (s[i][j] == '.' && !vis[i][j])
            {
                region++;
                bfs(i, j);
                // cout << i << " " << j << endl;
            }
        }
    }

    // cout << region << endl;
    int ans = 0;
    if (region == 1)
    {
        for (int i = 1; i + 1 < n; i++)
        {
            if (s1[i] == '.')
            {
                if (s2[i + 1] == 'x' &&  s2[i] == '.' && s2[i - 1] == 'x' && left[i - 1] > 0 && right[i + 1] > 0)
                    ans++;
            }
            if (s2[i] == '.')
            {
                if (s1[i + 1] == 'x' && s1[i] == '.' && s1[i - 1] == 'x' && left[i - 1] > 0 && right[i + 1] > 0)
                    ans++;
            }
        }
    }
    else if (region == 2)
    {
        for (int j = 0; j < n; j++)
        {
            if (j-1 >= 0 && left[j - 1] > 0 && ((s[0][j] == '.' && s[1][j] == 'x') || (s[1][j] == '.' && s[0][j] == 'x')))
                ans++;
        }
        ans++;
    }
    else ans = 0;

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