#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
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
        int odd_cnt = 0;
        vector<int> odd, even;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 0) even.push_back (x);
            else odd.push_back (x);

            if (x > 0 && x % 2 != 0) odd_cnt++;
        }

        int ans = 0;
        for (auto u : even)
        {
            if (u > 0) ans += u;
        }
        // cout << ans << endl;

        sort (rall (odd));
        ans += odd[0];
        // cout << ans << endl;
        for (int i = 1; i < odd.size(); i++)
        {
            if ((ans+odd[i]) > ans && (ans+odd[i]) % 2 != 0) 
            {
                ans += odd[i];
                // cout << ans << endl;
            }
            else if ((ans+odd[i]+odd[i+1]) > ans && (ans+odd[i]+odd[i+1]) % 2 != 0 && (i+1) < odd.size())
            {
                ans += odd[i];
                ans += odd[i+1];
                i++;
                // cout << ans << endl;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}