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
    fraction();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++) cin >> v[i];

        ll sum = 0;
        int week = n - k + 1;
        ll sumOfFirstWeek = 0;
        for (int i = 1; i <= k; i++)
        {
            sumOfFirstWeek += v[i];
        }
        ll recentvWeek = sumOfFirstWeek;
        // cout << recentvWeek << endl;

        for (int i = 1; i <= week; i++)
        {
            sum += recentvWeek;
            recentvWeek = (recentvWeek - v[i] + v[k+1]);
            k++;
            // cout << i << " " << sum << ' ' << recentvWeek << endl;
        }

        double avg = (1.00 * sum) / week;
        cout << avg << endl;
    }
    
    return 0;
}