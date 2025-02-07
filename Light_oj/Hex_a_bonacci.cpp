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
const int MX = 1e5+123;
const ll infLL = 9000000000000000000;
#define MOD 10000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }

int v[MX];
int dp[MX];

int fun (int n)
{
    if (n < 0) return 0;
    if (n <= 6) return v[n] % MOD;

    if (dp[n] != -1) return dp[n];
    return dp[n] = (fun(n-1) + fun(n-2) + fun(n-3) + fun(n-4) + fun(n-5) + fun(n-6)) % MOD;
}

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        mem (v, 0);
        mem (dp, -1);
        
        ll sum = 0;
        for (int i = 0; i < 6; i++)
        {
            cin >> v[i];
            sum += v[i];
            sum %= MOD;
        }
        v[6] = sum % MOD;

        int n;
        cin >> n;

        ll ans = fun(n) % MOD;
        cout << ans << endl;
    }

    return 0;
}