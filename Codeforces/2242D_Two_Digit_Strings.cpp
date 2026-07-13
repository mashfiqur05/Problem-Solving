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
const int MX = 2e4+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

// dp[i][j] = max length of common substring such that 
// [1.. i] for string a and [1..j] for string b

void solve ()
{
    string a, b; cin >> a >> b;
    int sa = 0, sb = 0;
    for (int i = 0; i < a.size(); i++) sa += (a[i] - '0'), sa %= 10;
    for (int i = 0; i < b.size(); i++) sb += (b[i] - '0'), sb %= 10;
    
    if (sa != sb)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> pa, pb;
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += (a[i] - '0');
        sum %= 10;
        pa.push_back(sum);
    }

    sum = 0;
    for (int i = 0; i < b.size(); i++)
    {
        sum += (b[i] - '0');
        sum %= 10;
        pb.push_back(sum);  
    }

    int n = pa.size(), m = pb.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // dp[i][j] = dp[i-1][j-1] + 1 if pa[i-1] == pb[j-1]
    // otherwise dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pa[i-1] == pb[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m] << endl;
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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}