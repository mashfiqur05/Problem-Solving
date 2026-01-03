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
    cout <<"Case " << CaseNo << ": ";
    int n, k; cin >> n >> k;

    if (k > n) 
    {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int col = 0; col <= i; col++)
        {
            /* transition 
            dp[i][j] = number of way to put k rooks using i row
            if we are not putting rooks in row i then total ways dp[i-1][j]
            if we are putting rooks in row i then total ways dp[i-1][j-1] * (n - (j - 1)) //till now unused col n - j + 1. just combination of them
            combining these two got dp[i][col] += dp[i-1][col] + (dp[i-1][col-1] * (n-col+1));
            */
           
            if (col == 0)dp[i][col] += dp[i-1][col];
            else dp[i][col] += dp[i-1][col] + (dp[i-1][col-1] * (n-col+1));
        }
    }

    cout << dp[n][k] << endl;
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