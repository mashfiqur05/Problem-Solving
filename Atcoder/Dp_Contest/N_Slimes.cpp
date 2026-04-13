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
const int MOD = 1e9+7;


void solve (int CaseNo)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> prefix (n, 0);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + v[i];

    vector<vector<int>> dp (n+1, vector<int> (n+1, infLL));

    for (int i = 0; i <= n; i++) dp[i][i] = 0;
    auto sum = [&](int l, int r)
    {
        if (l == 0)
            return prefix[r];
        return prefix[r] - prefix[l - 1];
    };

    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l+len-1 < n; l++)
        {
            int r = l+len-1;
            for (int k = l; k < r; k++)
            {
                dp[l][r] = min (dp[l][k] + dp[k+1][r] + sum (l, r), dp[l][r]);
            }
        }
    }

    cout << dp[0][n-1] << endl;
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