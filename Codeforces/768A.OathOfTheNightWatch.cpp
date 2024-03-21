#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const ll MX = 1e5+123;
//vector<ll> arr(MX);

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n, 0);

        for (int i = 0; i < n; i++) cin >> arr[i];

        ll mn = arr[0];
        ll mx = arr[n-1];

        for (int i = 0; i < n; i++)
        {
            mn = min (arr[i], mn);
            mx = max (arr[i], mx);
        }
        
        ll ans = 0;
        

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mn && arr[i] < mx) ans++;
        }

        cout << ans << endl;
    }
    
    return 0;
}