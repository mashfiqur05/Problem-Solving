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
    fraction();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        int ox, oy, ax, ay, bx, by;
        cin >> ox >> oy >> ax >> ay >> bx >> by;

        double oa = sqrt(pow(ax - ox, 2) + pow(ay - oy, 2));
        double ob = sqrt(pow(bx - ox, 2) + pow(by - oy, 2));
        double ab = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

        double angle = acos((pow(oa, 2) + pow(ob, 2) - pow(ab, 2)) / (2 * oa * ob));
        double ans = angle * oa;
        cout << ans << endl;
    }
    
    return 0;
}