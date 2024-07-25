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

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        int sz = s.size();

        string t1 = "AHIMOTUVWXYbdoqpvwx";
        string t2 = "AHIMOTUVWXYdbopqvwx";
        string t3 = "AHIMOTUVWXYovwx";
        int n = t1.size();

        bool f = 0;

        for (int i = 0, j = sz-1; i < j; i++, j--)
        {
            f = 0;
            for (int k = 0; k < n; k++)
            {
                if (s[i] == t1[k] && s[j] == t2[k])
                {
                    f = 1;
                }
                // cout << f << endl;
            }
            if (!f) return cout << "NIE" << endl, 0;
        }

        if (sz & 1)
        {
            int x = sz / 2;
            char tmp = s[x];
            // cout << tmp << " " << x << endl;
            for (int i = 0; i < t3.size(); i++)
            {
                if (tmp == t3[i]) return cout << "TAK" << endl, 0;
            }
            return cout << "NIE" << endl, 0;
        }

        cout << "TAK" << endl;
    }
    
    return 0;
}