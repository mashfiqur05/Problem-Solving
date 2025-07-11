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
const int MX = 2123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, k;
int dp[MX][MX];
vector<int> divisors[MX];

void factors(int n)
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j * j <= i; j++) 
        {
            if (i % j == 0)
            {
                divisors[i].push_back (j);
                if (i / j != j) divisors[i].push_back (i / j);
            }
        }
    }
}

void solve (int CaseNo)
{
    cin >> n >> k;
    factors (n);
    
    // for (int i = 1; i <= n; i++) 
    // {cout << i << "--> "; 
    //     for (auto u : divisors[i]) cout << u << " "; cout << endl;
    // }

    /// Base Case
    for (int i = 1; i <= k; i++) dp[1][i] = 1;
    for (int i = 1; i <= n; i++) dp[i][k] = 1;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++) cout << dp[i][j] << " "; cout << endl;
    // }

    for (int i = k-1; i >= 1; i--)
    {
        // cout << i << "---->" << endl;
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = 0;
            for (auto u : divisors[j])
            {
                // cout << u << "-->"  << dp[u][i+1] << endl;
                dp[j][i] += dp[u][i + 1];
                dp[j][i] %= MOD;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= k; j++) cout << dp[i][j] << " "; cout << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i][1];
        ans %= MOD;
    }

    cout << ans << endl;
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