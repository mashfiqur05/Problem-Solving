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
const int N = 1e3+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int h, w, dp[N][N];
char grid[N][N];

int fun (int i, int j)
{
    if (i == h-1 && j == w-1) return 1;
    if (i == h || j == w || grid[i][j] == '#') return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ret = 0;
    if (grid[i+1][j] == '.')ret += fun (i+1, j) % MOD;
    if (grid[i][j+1] == '.')ret += fun (i, j+1) % MOD;

    return dp[i][j] = ret % MOD;
}   

void solve ()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++) cin >> grid[i][j];
    }
    mem (dp, -1);

    cout << fun (0, 0) << endl;
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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}