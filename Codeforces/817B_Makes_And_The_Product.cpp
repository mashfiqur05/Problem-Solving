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
        vector<int> v (n);
        map<int, int> cnt;
        vector<pair<int,int>> vp;
        for (int i = 0; i < n; i++) cin >> v[i];
        sort (all (v));
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= v[2]) cnt[v[i]]++;
        }

        for (auto u : cnt) vp.push_back (u);

        int sz = vp.size();

        if (sz == 1)
        {
            int x = vp[0].second;
            cout << x * (x - 1) * (x - 2) / 6;
        }
        else if (sz == 2)
        {
            if (vp[0].second == 1) 
            {
                int x = vp[1].second;
                cout << x * (x-1) / 2;
            }
            else if (vp[0].second == 2)
            {
                cout << vp[1].second;
            }
        }
        else if (sz == 3) cout << vp[2].second;
    }
    
    return 0;
}