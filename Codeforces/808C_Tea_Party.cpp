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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, w;
        cin >> n >> w;
        vector<int> v(n);
        vector<pair<int, int>> p;
        vector<int> res(n);
        ll atleast = 0, remain = w;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            res[i] = (v[i] + 1) / 2;
            atleast += res[i];
            remain -= res[i];
            p.push_back ({v[i], i});
        }

        if (atleast > w) return cout << -1 << endl,0;

        for (int i = 0; i < n; i++)
        {
            p[i].first -= res[i];
        }
        while (remain)
        {
            sort (rall (p));
            for (int i = 0; i < n; i++)
            {
                if (remain == 0) break;
                if (p[i].first)
                {
                    res[p[i].second]++;
                    remain--;
                    p[i].first--;
                }
            }
        }

        for (auto u : res) cout << u << " ";
    }
    
    return 0;
}