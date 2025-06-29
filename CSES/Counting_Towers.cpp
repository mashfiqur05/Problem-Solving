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
const int MX = 1e6+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

/// O(n+t)

vector<vector<int>> dp(MX, vector<int>(2, 0));

void testCases (int tt)
{
    int n;
    cin >> n;
    
    int ans = (dp[MX-n][0] + dp[MX-n][1]) % MOD;
    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    dp[MX-1][0] = 1, dp[MX-1][1] = 1;

    for (int i = MX-2; i >= 0; i--)
    {
        dp[i][0] = (2 * dp[i+1][0] + dp[i+1][1]) % MOD;
        dp[i][1] = (4 * dp[i+1][1] + dp[i+1][0]) % MOD;
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}