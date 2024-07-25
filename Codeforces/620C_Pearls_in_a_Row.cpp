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

const int MX = 3e5+123;
int ans[MX][2];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, seg = 0, l = 1;
        cin >> n;
        set<int> s;
        vector<int> v(n+1);

        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            if (s.count (v[i]) > 0)
            {
                ans[seg][0] = l;
                ans[seg][1] = i;
                l = i+1;
                seg++;
                s.clear();
            }
            else s.insert(v[i]);
        }

        if (seg == 0) cout << "-1" << endl;
        else 
        {
            cout << seg << endl;
            ans[seg-1][1] = n;
            for (int i = 0; i < seg; i++)
            {
                cout << ans[i][0] << " " << ans[i][1] << endl;
            }
        }

    }
    
    return 0;
}