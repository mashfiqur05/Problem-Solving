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

int digitSum (int n)
{
    int ret = 0;
    while (n)
    {
        ret += (n % 10);
        n /= 10;
    }

    return ret;
}

ll power (int n, int x)
{
    ll ret = 1;
    for (int i = 1; i <= x; i++)
    {
        ret *= n;
    }

    return ret;
}


int32_t main()
{
    fastio();

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> ans;
        for (int i = 1; i <= 81; i++)
        {
            ll tmp = b * power (i, a) + c;
            
            if (digitSum (tmp) == i && tmp < 1e9) ans.push_back (tmp);
        }

        sort (all (ans));
        cout << ans.size() << endl;
        for (auto u : ans) cout << u << " ";
        cout << endl;
    }

    return 0;
}