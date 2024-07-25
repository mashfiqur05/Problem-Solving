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

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int hour, min, plus;
        char c;
        cin >> hour >> c >> min >> plus;
        
        int h_jog = plus / 60;
        int m_jog = plus % 60;

        min = min + m_jog;
        if (min >= 60) 
        {
            h_jog++;
            min %= 60;
        }
        hour = (hour + h_jog) % 24;

        if (hour > 9) cout << hour;
        else cout << '0' << hour;
        cout << c;
        if (min > 9) cout << min;
        else cout << '0' << min;
    }
    
    return 0;
}