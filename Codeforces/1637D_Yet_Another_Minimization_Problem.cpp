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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int total = 0;
    int sq = 0;

    for (int i = 0; i < n; i++)
    {
        total += a[i] + b[i];
        sq += a[i] * a[i] + b[i] * b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(10001, 0));

    dp[1][a[0]] = true;
    dp[1][b[0]] = true;

    for (int i = 2; i <= n; i++)
    {
        for (int s = 0; s <= 10000; s++)
        {
            if (s - a[i - 1] >= 0) dp[i][s] |= dp[i - 1][s - a[i - 1]];
            if (s - b[i - 1] >= 0) dp[i][s] |= dp[i - 1][s - b[i - 1]];
        }
    }

    int ans = infLL;

    for (int s = 0; s <= 10000; s++)
    {
        if (dp[n][s])
        {
            int sumA = s;
            int sumB = total - s;

            int cost = sumA * sumA + sumB * sumB;

            ans = min(ans, cost);
        }
    }

    cout << ans + (n - 2) * sq << endl;
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}