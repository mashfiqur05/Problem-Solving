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
int n, og, ng;
int oxygen[MX], nitrogen[MX], cylinder[MX], dp[MX][30][85];


int fun (int pos, int oxy, int nitro)
{
    if (oxy <= 0 && nitro <= 0) return 0;
    if (pos < 0) return 1e9;

    if (dp[pos][oxy][nitro] != -1) return dp[pos][oxy][nitro];

    int val1 = fun (pos-1, oxy, nitro);
    int val2 = fun (pos-1, max (0, oxy-oxygen[pos]), max (0, nitro-nitrogen[pos])) + cylinder[pos];

    return dp[pos][oxy][nitro] = min (val1, val2);
}

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        mem (dp, -1);
        mem (oxygen, 0);
        mem (nitrogen, 0);
        mem (cylinder, 0);
        cin >> og >> ng >> n;
        for (int i = 0; i < n; i++) cin >> oxygen[i] >> nitrogen[i] >> cylinder[i];

        int ans = fun (n-1, og, ng);
        cout << ans << endl;
    }

    return 0;
}