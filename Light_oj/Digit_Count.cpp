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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve (int CaseNo)
{
    cout << "Case " << CaseNo << ": ";
    int m, n; cin >> m >> n;
    vector<bool> f(10, 0);
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        f[x] = true;
    }

    vector<vector<int>> dp(n+1, vector<int> (10, 0));

    // base case -> can start with that digit that exist in the given set.
    for (int i = 0; i < 10; i++)
    {
        if (f[i]) dp[1][i] = 1;
    }

    for (int i = 2; i <= n;i++) 
    {
        for (int j = 0; j < 10; j++)
        {
            if (!f[j]) continue;
            for (int k = -2; k <= 2; k++)  // difference can be at most 2.
            {
                if (j+k >= 0 && j+k < 10) dp[i][j] += dp[i-1][j+k];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        if (f[i]) ans += dp[n][i];
    }

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