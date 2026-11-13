///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define endl '\n'
#define ll long long
#define int long long

const int MOD = 998244353;
const int MAXV = 600005;

int n, mx = 0, dp[MAXV][8][3];  
bool a[MAXV];

void solve ()
{
    cin >> n;
    vector<int> v(n);
    mx = 0;
    for (auto &x : v) { cin >> x; mx = max(mx, x); }

    for (int i = 0; i <= mx; i++) a[i] = false;
    for (int x : v) a[x] = true;

    for (int m = 0; m < 8; m++)
        for (int k = 0; k < 3; k++)
            dp[0][m][k] = 1;

    for (int pos = 1; pos <= mx; pos++)
    {
        for (int mask = 0; mask < 8; mask++)
        {
            int nmask = (mask << 1) & 7;
            int pc = __builtin_popcount(mask);

            for (int k = 0; k < 3; k++)
            {
                int ret = dp[pos-1][nmask][k];

                if (a[pos] && (k < 2 || pc == 2))
                {
                    ret += dp[pos-1][nmask | 1][k + (pc != 2)];
                    if (ret >= MOD) ret -= MOD;
                }
                dp[pos][mask][k] = ret;
            }
        }
    }

    int ans = dp[mx][0][0];
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;
}

int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}