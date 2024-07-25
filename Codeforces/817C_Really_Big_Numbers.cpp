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

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int N = 1e5+123;
//int arr[N];
ll n, s;

ll differnceOfSumAndNumber (ll x)
{
    ll sum = 0, tmp = x;
    while (tmp)
    {
        sum += (tmp % 10);
        tmp /= 10;
    }

    return abs (sum - x);
}


int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cin >> n >> s;

        ll l = 1, r = n;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;

            ll diff = differnceOfSumAndNumber (mid);
            if (diff < s) 
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }       

        ll ans = n - max (l, r) + 1;

        cout << ans << endl;
    }
    
    return 0;
}