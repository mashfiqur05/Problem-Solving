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

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const ll MX = 123;
//int arr[MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, f;
        cin >> n >> f;

        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            vp.push_back ({a, b});
        }

        vector<int> diff;
        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            int tmp1 = min (vp[i].first, vp[i].second);
            int tmp2 = min (vp[i].first * 2, vp[i].second);

            diff.push_back (tmp2 - tmp1);
            sum += tmp1;
        }

        sort (rall (diff));

        for (int i = 0; i < f; i++)
        {
            sum += diff[i];
        }

        cout << sum << endl;
    }
    
    return 0;
}