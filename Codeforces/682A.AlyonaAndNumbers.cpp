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

const ll MX = 123;
ll arr[5];
ll brr[5];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll a, b;
        cin >> a >> b;

        ll n = min (a, b);
        ll m = max (a, b);

        for (int i = 1; i <= m; i++) arr[i % 5]++;
        for (int i = 1; i <= n; i++) brr[i % 5]++;

        ll ans = 0;
        
        for (int i = 0; i < 5; i++) ans += 1LL * arr[i] * brr[(5-i) % 5];

        cout << ans << endl;

    }

    return 0;
}