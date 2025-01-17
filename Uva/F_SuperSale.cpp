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
const int MX = 1123;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }

int n, query;
int price[MX], weight[MX], person[123];
int dp[MX][35];

int solve (int pos, int w)
{
    if (w < 0) return INT_MIN;
    if (pos < 0) return 0;

    if (dp[pos][w] != -1) return dp[pos][w];

    int val1 = solve (pos - 1, w);
    int val2 = solve (pos - 1, w - weight[pos]) + price[pos];

    return dp[pos][w] = max (val1, val2);
}

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        mem (price, 0);
        mem (weight, 0);
        cin >> n;
        for (int i = 0; i < n; i++) cin >> price[i] >> weight[i];

        cin >> query;
        ll ans = 0;
        while (query--)
        {
            int q;
            cin >> q;
            ans += solve (n-1, q);
        }

        cout << ans << endl;
    }

    return 0;
}