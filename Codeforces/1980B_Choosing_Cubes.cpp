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
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int fav = v[f-1];
        sort (rall (v));
        bool f1 = 0, f2 = 0;
        for (int i = 0; i < k; i++)
        {
            if (v[i] == fav) 
            {
                f1 = 1;
                break;
            }
        }

        for (int i = k; i < n; i++)
        {
            if (v[i] == fav)
            {
                f2 = 1;
                break;
            }
        }

        if (f1 && f2) cout << "MAYBE" << endl;
        else if (f1 && !f2) cout << "YES" << endl;
        else if (!f1 && f2) cout << "NO" << endl;
    }
    
    return 0;
}