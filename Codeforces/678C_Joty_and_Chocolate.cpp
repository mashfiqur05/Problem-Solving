#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

int gcd ( int a, int b ) { return __gcd ( a, b ); }
int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int N = 1e5+123;
//int arr[N];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, a, b, p, q;
        cin >> n >> a >> b >> p >> q;

        vector<bool> isPaint(n+1, 0);
        int cnt1 = 0, cnt2 = 0;

        if (p < q) 
        {
            swap(p, q);
            swap (a, b);
        }

        cnt1 = n / a;
        int common = lcm (a, b);
        int badjabe = n / common;
        cnt2 = (n / b) - badjabe;

        // cout << cnt1 << " " << cnt2 << " " << badjabe << endl;
        ll ans = p * cnt1 + q * cnt2;

        cout << ans << endl;
    }
    
    return 0;
}