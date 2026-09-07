///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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
const int N = 423;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, a[N], dp[N][N], pref[N];

int fun (int l, int r)
{
    if (l == r) return 0;

    if (dp[l][r] != -1) return dp[l][r];

    int res = infLL;

    for (int i = l; i < r; i++)
    {
        res = min (res, (fun(l, i) + fun (i+1, r) + pref[r]-(l-1 >= 0 ? pref[l-1] : 0)));
    }

    return dp[l][r] = res;
}

void solve ()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i-1] + a[i];
        // cout << pref[i] << " ";
    }
    mem(dp, -1);

    cout << fun (0, n-1) << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         // cout << "L " << i << " R " << j << " " << dp[i][j] << endl;
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}