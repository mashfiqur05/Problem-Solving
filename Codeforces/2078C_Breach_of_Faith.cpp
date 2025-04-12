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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void testCases (int tt)
{
    ll n;
    cin >> n;
    vector<ll> v(2*n);
    set<int> s;
    for (int i = 0; i < 2*n; i++) {cin >> v[i]; s.insert (v[i]);}
    sort (rall (v));

    ll ans = 0;
    for (int i = 0; i < 2*n; i++)
    {
        if (i % 2 == 0) ans += v[i];
        else ans -= v[i];
    }

    auto it = s.find(ans);
    if (it == s.end() || ans <= 0)
    {
        cout << ans << " ";
        for (auto u : v)
            cout << u << " ";
        cout << endl;
    }
    else 
    {
        // cout << ans << endl;
        ll x = 0;
        for (int i = 0; i < n; i++) 
        {
            x += v[i];
        }
        for (int i = n; i < 2*n-1; i++) x -= v[i];

        x += v[2*n-1];

        // cout << x << endl;
        cout << v[2*n-1] << " " << x << " ";
        for (int i = 0, j = n; i < n && j < 2*n; i++, j++)
        {
            if (j == 2*n-1) cout << v[i] << " "; 
            else cout << v[i] << " " << v[j] << " ";
        }
        cout << endl;
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