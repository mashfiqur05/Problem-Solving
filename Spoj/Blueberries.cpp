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
int n, k;
int arr[1111];
int dp[1111][1111];


int fun (int pos, int baki_ace)
{
    if (baki_ace < 0) return INT_MIN;
    if (pos < 0) return 0;

    if (dp[pos][baki_ace] != -1) return dp[pos][baki_ace];

    int val1 = fun (pos - 1, baki_ace);
    int val2 = fun (pos - 2, (baki_ace - arr[pos])) + arr[pos];

    return dp[pos][baki_ace] = max (val1, val2);
}


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> arr[i];

        int ans = fun (n-1, k);
        cout << "Scenario #" << tt << ": " << ans << endl;
    }

    return 0;
}