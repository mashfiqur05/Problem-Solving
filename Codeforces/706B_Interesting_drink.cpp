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
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++) cin >> v[i];

        sort (all (v));
        
        int q;
        cin >> q;

        while (q--)
        {
            int x;
            cin >> x;
            
            int up = n; 
            int l = 0, r = n-1, mid;

            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (v[mid] > x)
                {
                    up = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            cout << up << endl;
        }
    }
    
    return 0;
}