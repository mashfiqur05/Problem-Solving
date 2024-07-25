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

//const int MX = 1e9+123;
//int arr[MX][MX];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        int ans = 0;

        int q;
        cin >> q;

        while (q--)
        {
            int xmove = 0, ymove = 0, dx, dy;
            cin >> dx >> dy;

            if (dx > 0)
            {
                xmove = (n - x) / dx;
            }
            else if (dx < 0)
            {
                xmove = (x - 1) / (-dx);
            }

            if (dy > 0) {ymove = (m - y) / dy;}
            else if (dy < 0) {ymove = (y - 1) / (-dy);}

            int move = min (abs (xmove), abs (ymove));

            if (!dx) move = ymove;
            if (!dy) move = xmove;

            ans += move;
            //cout << move << ' ' << xmove << ' ' << ymove << endl;

            x += move * dx;
            y += move * dy;
        }

        cout << ans << endl;
    }
    
    return 0;
}