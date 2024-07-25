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
        int n, m;
        cin >> n >> m;
        vector<int> city(n), tower(m);

        for (int i = 0; i < n; i++) cin >> city[i];
        for (int i = 0; i < m; i++) cin >> tower[i];

        sort (all (city));
        sort (all (tower));
        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int id = lower_bound (all (tower), city[i]) - tower.begin() - 1;
            int dis = INT_MAX;
            if (id >= 0) dis = min (dis, abs (city[i] - tower[id]));
            if (id + 1 < m) dis = min (dis, abs (tower[id+1] - city[i]));

            ans = max (ans, dis);
        }

        cout << ans << endl;
    }
    
    return 0;
}