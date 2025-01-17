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
const int MOD = 1e9+7;

int n, a[MX], b[MX], c[MX], dp[MX][4], vis[MX];

int fun (int ind, int choose)
{
    if (ind == n) return 0;
    if (dp[ind][choose] != -1) return dp[ind][choose];

    int res = 0;

    if (choose == 1) res = max (fun (ind + 1, 2), fun (ind+1, 3)) + a[ind]; 
    if (choose == 2) res = max (fun (ind + 1, 1), fun (ind+1, 3)) + b[ind]; 
    if (choose == 3) res = max (fun (ind + 1, 2), fun (ind+1, 1)) + c[ind];

    return dp[ind][choose] = res;
}


void solve (int testCase)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    mem (dp, -1);
    int ans = fun (0, 1);
    ans = max (ans, fun (0, 2));
    ans = max (ans, fun (0, 3));

    cout << ans << endl;
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