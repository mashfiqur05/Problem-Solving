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

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int N = 1e5+123;
//int arr[N];
const ll MOD = 1000000007;
ll fact[2000009];


void factorial()
{
    fact[0]=1;
    for(int i=1; i<2000002; i++)
    {
        fact[i]=(fact[i-1]%MOD*i)%MOD;
    }
}

ll BigMod( ll a , ll b )
{
    ll res = 1;
    while ( b )
    {
        if( b % 2 == 1 ) res = ( res * a ) % MOD ;
        a = ( a * a ) % MOD ;
        b /= 2 ;
    }
    return res ;
}

int32_t main()
{
    Bismillah();
    factorial();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        int n, k;
        cin >> n >> k;

        ll ans = (fact[n+k-1] * ( BigMod( (fact[n] * fact[k-1] )%MOD , MOD - 2 ))) % MOD ;
        cout << ans % MOD << endl;
    }
    
    return 0;
}