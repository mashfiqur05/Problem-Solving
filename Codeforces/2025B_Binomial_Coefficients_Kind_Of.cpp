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
const int MX = 1e5+5;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int dp[MX], n[MX], k[MX];

int fun (int k)
{
    if (k == 0) return 1;
    if (dp[k] != -1) return dp[k];

    return dp[k] = (fun (k-1) % MOD+ fun (k-1) % MOD) % MOD;
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) cin >> n[i];
        for (int i = 0; i < t; i++) cin >> k[i];

        for (int i = 0; i < t; i++)
        {
            if (n[i] == k[i]) cout << 1 << endl;
            else cout << fun (k[i]) << endl;
        }
    }

    return 0;
}