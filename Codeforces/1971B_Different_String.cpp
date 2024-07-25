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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;

        bool f = 0;
        char ch = s[0];
        int sz = s.size();
        int id;

        if (sz == 1)
        {
            f = 0;
        }
        else
        {
            for (int i = 0; i < sz; i++)
            {
                if (s[i] != ch)
                {
                    f = 1;
                    id = i;
                    break;
                }
            }
        }

        if (f == 0) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            swap (s[0], s[id]);
            for (auto u : s) cout << u;
            cout << endl;
        }
    }
    
    return 0;
}   