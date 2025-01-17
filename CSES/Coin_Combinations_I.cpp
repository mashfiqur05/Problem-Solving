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
int arr[105];
int dp[MX];

int solve (int required_coin)
{
    if (required_coin == 0) return 1;
    if (required_coin < 0) return 0;

    if (dp[required_coin] != -1) return dp[required_coin];

    ll way = 0;
    for (int i = 0; i < n; i++)
    {
        way += (solve (required_coin - arr[i]) % MOD);
        way %= MOD;
    }

    return dp[required_coin] = way % MOD;
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

        cout << solve (desire_coin) << endl;
    }

    return 0;
}