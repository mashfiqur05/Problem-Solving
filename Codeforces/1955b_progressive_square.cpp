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


int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n, c, d;
        cin >> n >> c >> d;

        vector<ll> arr(n * n);
        vector<ll> brr;

        ll mn = LONG_LONG_MAX;

        for (int i = 0; i < sq(n); i++)
        {
            cin >> arr[i];
            mn = min (mn, arr[i]);
        }

        brr.push_back (mn);

        queue<ll> q;
        q.push (mn);

        for (int i = 0; i < n-1; i++)
        {
            mn += d;
            brr.push_back (mn);
            q.push (mn);
        }

        for (int j = 0; j < n-1; j++)
        {
            ll sz = q.size();
            while (sz--)
            {
                ll f = q.front();
                q.pop();
                brr.push_back (f + c);
                q.push (f + c);
            }
        }

        sort (all (arr));
        sort (all (brr));

        if (arr == brr)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}