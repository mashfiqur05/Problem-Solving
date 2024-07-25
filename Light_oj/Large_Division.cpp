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
        cout << "Case " << tt << ": ";
        string a;
        ll b;
        cin >> a >> b;

        int sz = a.size();
        int ans = 0;
        if (b < 0) b = abs (b);

        for (int i = 0; i < sz; i++)
        {
            if (a[i] == '-') continue;
            ans = (1LL * ans * 10 + a[i] - '0')  % b;
            //cout << ans << endl;
        }

        if (ans == 0) cout << "divisible" << endl;
        else cout << "not divisible" << endl;
    }
    
    return 0;
}