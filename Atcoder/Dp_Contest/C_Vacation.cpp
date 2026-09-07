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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n, a[MX], b[MX], c[MX], dp[MX][4];

int fun (int pos,int prev)
{
    if (pos == n) return 0;

    if (dp[pos][prev] != -1) return dp[pos][prev];

    int ret = 0;
    if (prev == 1)
    {
        ret = max (ret, fun (pos+1, 2) + b[pos]);
        ret = max (ret, fun (pos+1, 3) + c[pos]);
    }
    else if (prev == 2)
    {
        ret = max (ret, fun (pos+1, 1) + a[pos]);
        ret = max (ret, fun (pos+1, 3) + c[pos]);

    }
    else if (prev == 3)
    {
        ret = max (ret, fun (pos+1, 1) + a[pos]);
        ret = max (ret, fun (pos+1, 2) + b[pos]);
    }
    else 
    {
        ret = max (ret, fun (pos+1, 1) + a[pos]);
        ret = max (ret, fun (pos+1, 2) + b[pos]);
        ret = max (ret, fun (pos+1, 3) + c[pos]);
    }

    return dp[pos][prev] = ret;
}

void solve ()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    mem (dp, -1);

    cout << fun (0, 0) << endl;
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