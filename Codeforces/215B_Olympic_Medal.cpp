#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int MX = 123;
//int arr[MX];

double get(int r1, int p1, double p2, int A, int B) 
{
    return sqrt(B*p1*r1*r1/(A*p2+B*p1));    
}

int32_t main()
{
    Bismillah();
    fraction();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m, k;
        cin >> n;
        vector<int> r(n);
        for (int i =  0; i < n; i++) cin >> r[i];
        cin >> m;
        vector<int> y(m);
        for (int i = 0; i < m; i++) cin >> y[i];
        cin >> k;
        vector<int> z(k);
        for (int i = 0; i < k; i++) cin >> z[i];
        int a, b;cin >> a >> b;

        double p2 = z[0];
        for (int i = 1; i < k; i++) p2 = min (p2, (double)z[i]);

        double ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max (ans, get (r[i], y[j], p2, a, b));
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}