#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const ll MX = 123;
//int arr[MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n, m;
        cin >> n >> m;

        vector<pair<ll, ll>> v;

        for (int i = 1; i <= m; i++)
        {
            ll a, b;
            cin >> a >> b;

            v.push_back ( {b, a} );
        }

        sort (rall (v));

        ll ans = 0;

        
        for (auto u : v)
        {
            if (u.second < n)
            {
                n -= u.second;
                ans += (u.second * u.first);
            }
            else 
            {
                ans += (n * u.first);
                break;
            }
        }
        
        cout << ans << endl;

        //for (auto u : v) cout << u.first << ' ' << u.second << endl;
    }
    
    return 0;
}