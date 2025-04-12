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
const int MX = 1e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int dp[MX][3], h1[MX], h2[MX];
int n;

int func (int pos, int last_choosen)
{
    if (pos == n) return 0;
    if (dp[pos][last_choosen] != -1) return dp[pos][last_choosen];

    int val = func (pos + 1, 0);
    if (last_choosen != 1) val = max (val, func (pos + 1, 1) + h1[pos]);
    if (last_choosen != 2) val = max (val, func (pos + 1, 2) + h2[pos]);

    return dp[pos][last_choosen] = val;
}


void testCases (int tt)
{
    mem (dp, -1);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h1[i];    
    for (int i = 0; i < n; i++) cin >> h2[i];
    
    int ans = func (0, 0);
    ans = max (ans, func (1, 0));
    
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
        testCases (tt);
    }

    return 0;
}       