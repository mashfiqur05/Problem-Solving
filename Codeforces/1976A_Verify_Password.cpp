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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string dig = "";
        string alp = "";

        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != n-1 && (s[i+1] >= '0' && s[i+1] <= '9') && (s[i] >= 'a' && s[i] <= 'z'))
            {
                f = 0;
                break;
            }

            if (s[i] >= '0' && s[i] <= '9') dig += s[i];
            else if (s[i] >= 'a' && s[i] <= 'z') alp += s[i];
            else 
            {
                f = 0;
                break;
            }
        }

        string tmp1 = dig;
        sort (all (tmp1));
        if (tmp1 != dig) f = 0;

        string tmp2 = alp;
        sort (all (tmp2));
        if (tmp2 != alp) f = 0;

        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}