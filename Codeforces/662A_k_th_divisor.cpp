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
        ll n, k;
        cin >> n >> k;
        vector<int> div;

        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                div.push_back (i);
                if (i * i != n) div.push_back ((n/i));
            }
        }

        sort (all(div));
        // // cout << div.size() << endl;
        // for (auto u : div) cout << u << " ";
        // cout << endl;

        k--;

        if (div.size() <= k) cout << "-1" << endl;
        else cout << div[k] << endl;
    }
    
    return 0;
}