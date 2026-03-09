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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 998244353;


void solve (int CaseNo)
{
    int q, k; cin >> q >> k;
    vector<int> dp(k+1, 0);
    dp[0] = 1;

    while (q--)
    {
        char sign;int x; cin >> sign >> x;
        if (sign == '+')
        {
            for (int i = k-x; i >= 0; i--)
            {
                dp[i+x] += dp[i];
                dp[i+x] %= MOD;
            }
        }
        else
        {
            for (int i = 0; i <= k-x; i++)
            {
                dp[i+x] -= dp[i];
                if (dp[i+x] < 0) dp[i+x] += MOD;
            }
        }

        // cout << x << " " << dp[x] << endl;
        cout << dp[k] << endl;
    }
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