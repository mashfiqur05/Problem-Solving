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
        int hour, min;
        char c;
        cin >> hour >> c >> min;
        
        bool day = 1;

        if (hour >= 13 && hour <= 23)
        {
            hour -= 12;
            day = 0;
        }
        else if (hour == 0)
        {
            hour = 12;
        }
        else if (hour == 12)
        {
            day = 0;
        }

        if (hour >= 0 && hour <= 9)
        {
            cout << 0 << hour;
        }
        else
        {
            cout << hour;
        }

        cout << ':';

        if (min >= 0 && min <= 9)
        {
            cout << 0 << min;
        }
        else
        {
            cout << min;
        }

        if (day)
        {
            cout << ' ' << "AM" << endl;
        }
        else
        {
            cout << ' ' << "PM" << endl;
        }
    }
    
    return 0;
}