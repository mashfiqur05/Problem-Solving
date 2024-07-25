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
int seg[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calculateSegment (int n)
{
    int sum = 0;
    while (n)
    {
        int tmp = n % 10;
        n /= 10;
        sum += seg[tmp];
    }
    return sum;
}

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;

        for (int i = a; i <= b; i++)
        {
            ans += calculateSegment (i);
        }

        cout << ans << endl;

    }
    
    return 0;
}