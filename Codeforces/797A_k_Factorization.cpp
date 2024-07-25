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
        int n, k;
        cin >> n >> k;
        int tmp = k;
        k--;

        vector<int> ans;
        ans.push_back (n);

        while (k-- && n > 1)
        {
            for (int i = 2; i <= n; i++)
            {
                if (n % i == 0 && (n / i) > 1)
                {
                    n /= i;
                    ans.pop_back();
                    ans.push_back (i);
                    ans.push_back (n);
                    // cout << i << " " << n << endl;
                    break;
                }
            }
        }
        if (ans.size() != tmp) cout << -1 << endl;
        else
        {
            for (auto u : ans) cout << u << ' ';
        }
    }
    
    return 0;
}