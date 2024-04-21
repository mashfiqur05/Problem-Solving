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
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        int dig1 = n % 10;
        int dig2 = n / 10;

        int arr[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
        
        /*
        0 = 0, 8
        1 = 0, 1, 3, 4, 7, 8, 9
        2 = 2, 8
        3 = 3, 8, 9
        4 = 4, 8, 9
        5 = 5, 6, 8, 9
        6 = 6, 8
        7 = 0, 3, 7, 8, 9
        8 = 8
        9 = 8, 9
        */

        int ans = arr[dig1] * arr[dig2];

        cout << ans << endl; 
    }
    
    return 0;
}