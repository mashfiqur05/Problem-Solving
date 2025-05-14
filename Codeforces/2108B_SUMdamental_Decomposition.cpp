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


void testCases (int tt)
{
    int n, x;
    cin >> n >> x;
    if (x == 0) 
    {
        if (n == 1) cout << -1 << endl;
        else if (n % 2 == 0) cout << n << endl;
        else cout << n + 3 << endl;

        return;
    }
    if (x == 1)
    {
        if (n & 1) cout << n << endl;
        else cout << n + 3 << endl;

        return;
    }

    int cnt = __builtin_popcountll(x);

    // cout << cnt << " " << n-cnt << endl;
    if (cnt >= n) cout << x << endl;
    else 
    {
        int ans = x;
        n -= cnt;
        if (n % 2 == 0) ans += n;
        else ans += (n + 1);

        cout << ans << endl;
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}