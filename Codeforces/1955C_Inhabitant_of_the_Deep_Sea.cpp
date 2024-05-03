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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> v(n+1), pre(n+1, 0), back_pre(n+2, 0);

        for (int i = 1; i <= n; i++) 
        {
            cin >> v[i];
            pre[i] = pre[i-1] + v[i];
        }

        for (int i = n; i >= 1; i--)
        {
            back_pre[i] = back_pre[i+1] + v[i];
        }

        if (k >= pre[n]) cout << n << endl;
        else
        {
            ll tmp1 = (k+1) / 2;
            ll tmp2 = k - tmp1; 
            ll f1 = 0, f2 = 0;

            for (int i = 1; i <= n; i++)
            {
                //cout << pre[i] << ' ';
                if (tmp1 >= pre[i])
                {
                    f1++;
                }
                else break;
            }
            for (int i = n; i >= 1; i--)
            {
               // cout << back_pre[i] << ' ';
                if (tmp2 >= back_pre[i])
                {
                    f2++;
                }
                else break;
            }

            //cout << f1 << ' ' << f2 << endl;
            //cout << tmp1 << ' ' << tmp2 << endl;

            cout << f1+ f2 << endl;
        }
    }
    
    return 0;
}