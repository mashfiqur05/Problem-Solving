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
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int n;
int arr[20][20], dp[20][(1 << 17) + 5];


int solve (int row, int mask)
{
    if (mask == (1 << n) - 1 ) return 0;
    if (row == n) return 0;

    if (dp[row][mask] != -1) return dp[row][mask];

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i)) continue;
        int val = solve (row + 1, (mask | (1 << i))) + arr[row][i];
        ret = max (ret, val);
    }

    return dp[row][mask] = ret;
}


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        cin >> n;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) cin >> arr[i][j];
        }
        cout << "Case " << tt << ": ";

        cout << solve (0, 0) << endl;
    }

    return 0;
}