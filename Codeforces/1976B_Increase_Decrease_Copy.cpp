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

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n+1);
        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n+1; i++)
        {
            cin >> b[i];
        }
        int x = b[n];
        int mn = 1e9+12;
        bool f = 1;

        for (int i = 0; i < n; i++)
        {
            ans += abs (a[i] - b[i]);
            mn = min (mn, min (abs (a[i] - x), abs (b[i] - x)));
            //cout << "mn " << mn << endl;
            if ((x >= a[i] && x <= b[i]) || (x <= a[i] && x >= b[i])) f = 0;
        }
        //cout << "ans = "<< ans << endl;
        if (f) ans += mn;
        cout << ++ans << endl;
    }
    
    return 0;
}