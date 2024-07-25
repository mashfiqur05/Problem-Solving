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

int gcd ( int a, int b ) { return __gcd ( a, b ); }
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
        
        vector<int> ans;
        int cnt = 0;

        for (int i = 0; i < n-1; i++)
        {
            if (gcd (v[i], v[i+1]) != 1) 
            {
                ans.push_back (v[i]);
                ans.push_back (1);
                cnt++;
            }
            else ans.push_back (v[i]);
        }
        ans.push_back (v[n-1]);

        cout << cnt << endl;
        for (auto u : ans) cout << u << " ";

        
    }
    
    return 0;
}