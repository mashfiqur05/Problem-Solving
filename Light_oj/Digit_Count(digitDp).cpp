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

int n, m;
vector<int> s;
int dp[12][12];

int fun (int pos, int prev)
{
    if (pos == n) return 1;
    if (dp[pos][prev] != -1) return dp[pos][prev];

    int res = 0;
    for (auto u : s)
    {
        if (abs (u-prev) <=2) res += fun (pos+1, u);
    }

    return dp[pos][prev] = res;
}

void solve (int CaseNo)
{
    s.clear();
    cin >> m >> n;
    for (int i = 0; i < m; i++) 
    {
        int x; cin >> x;
        s.push_back (x);
    }    

    mem (dp, -1);
    int ans= 0;
    for (auto u : s) {
        ans += fun (1, u);
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        solve (tt);
    }

    return 0;
}