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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int extendedGcd(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extendedGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

ll modInverse(ll a, ll mod) {
    ll x, y;
    extendedGcd(a, mod, x, y);

    x %= mod;
    if (x < 0) x += mod;

    return x;
}


int countAllSol(int a, int b, int n, int g, int x, int y, int invA)
{
    if (n < 0 || n % g != 0) return 0;

    n /= g;

    if (y == 1) {
        return n / x + 1;
    }

    int x0 = (n % y) * invA % y;
    int maxX = n / x;
 
    if (x0 > maxX) return 0;
 
    return (maxX - x0) / y + 1;
}

void solve ()
{
    int a, b, c, p; cin >> a >> b >> c >> p;

    int gAll = __gcd(a, __gcd(b,c));
    if (p % gAll != 0)
    {
        cout << 0 << endl;
        return;
    }

    a /= gAll; b/= gAll; c /= gAll; p/=gAll;

    int g = __gcd(a, b);
    int na = a/g, nb= b/g;

    int invA = 0;
    if (nb != 1)
    {
        invA = modInverse(na % nb, nb);
    }

    int ans = 0;

    for (int i = 0; i *c <= p; i++)
    {
        int rem = p - i * c;

        ans += countAllSol(a, b, rem, g, na, nb, invA);
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        solve ();
    }

    return 0;
}