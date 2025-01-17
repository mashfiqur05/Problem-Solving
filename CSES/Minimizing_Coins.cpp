///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 1e6+123;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int n, desire_coin;
int arr[MX];
int dp[MX];


int solve (int remain_coin)
{
    if (remain_coin < 0) return INT_MAX;
    if (remain_coin == 0) return 0;

    if (dp[remain_coin] != -1) return dp[remain_coin];

    int val = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int res = solve(remain_coin - arr[i]);  // Try using coin arr[i]
        if (res != INT_MAX) {
            val = min(val, res + 1);  // Update the minimum if valid
        }
    }

    return dp[remain_coin] = val;
}


int32_t main()
{
    fastio();

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        cin >> n >> desire_coin;
        for (int i = 0; i < n; i++) cin >> arr[i];

        int ans = solve (desire_coin);

        if (ans == INT_MAX) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}