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
//vector<ll> arr(MX);

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int row1, row2, col1, col2, diagon1, diagon2;
        cin >> row1 >> row2 >> col1 >> col2 >> diagon1 >> diagon2;

        int a, b, c, d;

        for (int i = diagon1-1; i >= 1; i--)
        {
            a = i; 
            b = row1 - a;
            c = col1 - a; 
            d = row2 - c;

            if ((b+d == col2) && (a+d == diagon1) && (b+c == diagon2))  /// checking for another row, col, diagonal.
            {
                if (a > 0 && a <= 9 && b > 0 && b <= 9 && c > 0 && c <= 9 && d > 0 && d <= 9)   /// checking for 1 to 9
                {
                    if (a != b && a != c && a != d && b != c && b != d && c != d)   /// checking for distinct
                    {
                        return cout << a << ' ' << b << endl << c << ' ' << d << endl, 0;
                    }
                }
            }
        }

        cout << "-1" << endl;
    }
    
    return 0;
} 