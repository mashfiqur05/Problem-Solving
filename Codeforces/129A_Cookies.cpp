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
        int n;
        cin >> n;
        vector<int> v(n);

        int sum = 0, oddcnt = 0, evencnt = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            if (v[i] % 2 == 0) evencnt++;
            else oddcnt++;
        }

        if (sum % 2 == 0) cout << evencnt<< endl;
        else cout << oddcnt << endl;
    }
    
    return 0;
}