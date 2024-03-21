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

const ll MX = 1e5+123;
vector<ll> arr(MX);
vector<ll> mx(MX);
vector<ll> mn(MX);

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> arr[i];

        // for 1st and last index
        mn[1] = abs (arr[2] - arr[1]);
        mx[1] = mx[n] = abs (arr[n] - arr[1]);
        mn[n] = abs (arr[n] - arr[n-1]);

        for (int i = 2; i <= n-1; i++)
        {
            mn[i] = min (abs (arr[i+1] - arr[i]), abs (arr[i] - arr[i-1]));
            mx[i] = max (abs (arr[n] - arr[i]), abs (arr[i] - arr[1]));
        }

        for (int i = 1; i <= n; i++) cout << mn[i] << ' ' << mx[i] << endl;
    }
    
    return 0;
}