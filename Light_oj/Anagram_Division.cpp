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
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }

string s;
int d;
int dp[(1 << 10) + 5][1005];


int fun (int mask, int mod)
{
    if (mask == (1 << s.size()) - 1) return (mod == 0);

    if (dp[mask][mod] != -1) return dp[mask][mod];

    int ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((1 << i) & mask) continue;
        int val = fun (mask | (1 << i), (mod * 10 + s[i] - '0') % d);

        ret += val;
    } 

    return dp[mask][mod] = ret;
}


int32_t main()
{
    fastio();

    vector<ll> fact (10);
    fact[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        fact[i] = fact[i-1] * i;
    }

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        cout << "Case " << tt << ": ";    
        cin >> s >> d;

        int ans = fun (0, d);

        map<int, int> cnt;
        for (auto c : s) cnt[c - '0']++;

        for (int i = 0; i < 10; i++)
        {
            ans /= fact[cnt[i]];
        }

        cout << ans << endl;
    }

    return 0;
}