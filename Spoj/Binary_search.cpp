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
        int n, q;
        cin >> n >> q;
        vector<int> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];

        while (q--)
        {
            int x;
            cin >> x;
            int l = 0, r = n - 1, ans = -1;

            while (l <= r)
            {
                int mid = (l + r) / 2;

                if (v[mid] == x)
                {
                    ans = mid;
                    //cout << "mid " << mid << endl;
                    int i = mid;
                    while (v[i] == x && i >= 0)
                    {
                        ans = i;
                        i--;
                      //  cout << i << endl;
                    }
                    break;
                }

                if (v[mid] < x) l = mid + 1;
                else r = mid - 1;
            }

            cout << ans << endl;
        }

    }
    
    return 0;
}