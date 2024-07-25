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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        vector<int> v;
        int sum = 0;
        for (int i = 0; i < 6; i++) 
        {
            int a; cin >> a;
            v.push_back (a);
            sum += a;
            sum = sum % 10000007;
        }

        int n;
        cin >> n;
        
        v.push_back (sum);
        if (n <= 6) cout << "Case " << tt << ": " << v[n] % 10000007 << endl;
        else 
        {
            for (int i = 7; i <= n; i++)
            {
                int tmp = v[i-1] + v[i-2] + v[i-3] + v[i-4] + v[i-5] + v[i-6];
                tmp = tmp % 10000007;
                //cout << i << " = " << tmp << endl;
                v.push_back (tmp); 
            }
            cout << "Case " << tt << ": " << v[n] % 10000007<< endl;
        }
    }
    
    return 0;
}   