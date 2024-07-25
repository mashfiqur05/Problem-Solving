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

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

const int N = 1e5+123;
//int arr[N];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        vector<int> v (n), ans(n);
        // bool f1 = 1;
        // int fast;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            ans[i] = n;
        }
        
        int dis = -n;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0) dis = i;
            ans[i] = min (ans[i], i - dis);
        }

        // for (auto u : ans) cout << u << " ";
        // cout << endl;

        dis = 2 * n;
        for (int i = n-1; i >= 0; i--)
        {
            if (v[i] == 0)
            {
                dis = i;
            }
            ans[i] = min (ans[i], dis-i);
                
        }

        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    
    return 0;
}