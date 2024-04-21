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
        int n, q;
        cin >> n >> q;

        vector<bool> v(n+1, 1);
        vector<int> t(q+1);

        for (int i = 1; i <= q; i++) cin >> t[i];

        for (int i = 1; i <= q; i++)
        {
            v[t[i]] = !(v[t[i]]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if(v[i] != 0) ans++;
        }

        cout << ans << endl;
    }
    
    return 0;
}