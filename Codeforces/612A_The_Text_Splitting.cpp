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
        int n, p, q;
        cin >> n >> p >> q;
        string s;
        cin >> s;

        for (int i = 0; i <= n / p; i ++)
        {
		    if ((n - i * p) % q == 0)
            {
			    int x = i, y = (n - i * p) / q;
			    cout << x + y << '\n';
			    
                for (int j = 0; j < x; j ++) cout << s.substr(j * p, p) << '\n';
			    
                for (int j = 0; j < y; j ++) cout << s.substr(x * p + j * q, q) << '\n';
			   
                return 0;
		    }
	    }

        cout << "-1" << endl;
    }
    
    return 0;
}