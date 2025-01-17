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
const int MX = 1123;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int n;
vector<pair<int, int>> v(MX);
int dp[MX][2*MX];


int lis (int pos, int prev)
{
    if (pos > n) return 0;

    if (dp[pos][prev] != -1) return dp[pos][prev];

    int val1 = lis (pos+1, prev);
    if (!prev || v[prev].second <= v[pos].second) 
    {
        val1 = max (val1, lis (pos+1, pos) + 1);
    }

    return dp[pos][prev] = val1;
}

int32_t main()
{
    fastio();
    
    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        cin >> n;
        v.resize(n+1);
        for (int i = 1; i <= n; i++) cin >> v[i].first;
        for (int i = 1; i <= n; i++) cin >> v[i].second;

        sort (all (v));

        int ans = lis (1, 0);

        cout << ans << endl;
        
    }

    return 0;
}