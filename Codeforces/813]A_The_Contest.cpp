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

//const int N = 1e5+123;
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
        vector<int> v (n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int m;
        cin >> m;
        vector<pair<int, int>> time(m);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            time.push_back ({a, b});
        }
        sort (all (time));
        int sum = 0;
        for (auto u : v)
        {
            sum += u;
        }

        bool f = 0;
        for (auto u : time)
        {
            if (sum <= u.second)
            {
                sum = max (sum, u.first);
                f = 1;
                break;
            }        
        }

        if (f) cout << sum << endl;
        else cout << -1 << endl;
    }
    
    return 0;
}