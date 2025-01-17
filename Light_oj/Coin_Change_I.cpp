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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
#define MOD 100000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int n, k;
int a[55], c[55];
int dp[55][1005];

int fun (int pos, int left)
{
    if (left < 0) return 0;
    if (left == 0) return 1;
    if (pos == n) return 0;

    if (dp[pos][left] != -1) return dp[pos][left];

    int val = 0;
    for (int i = 0; i <= c[pos]; i++)
    {
        val += fun (pos+1, left - i * a[pos]);
        val %= MOD;
    }

    return dp[pos][left] = val % MOD;
}

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        mem (a, 0);
        mem (c, 0);
        cout << "Case " << tt << ": ";
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        int ans = fun (0, k);
        cout << ans << endl;
    }

    return 0;
}