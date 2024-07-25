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
        int n, m, k;
        cin >> n >> m >> k;
        set<pair<int, int>> s;
        for (int i = 1; i <= k; i++)
        {
            int a;
            cin >> a;
            s.insert ({i, a});
        }
        int ans = 0;
        
        //for (auto u : s) cout << u.second;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x;
                cin >> x;
                for (auto u : s)
                {
                    ans++;
                    //cout << ans << " " << u.second << endl;
                    if (x == u.second)
                    {
                        s.erase (u);
                        s.insert ({-(i * m + j), x});
                        // for (auto u : s) cout << u.second;
                        // cout << endl;
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}