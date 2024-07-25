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
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, m;
        cin >> n >> m;

        deque<int> dq;
        for (int i = 0; i < n; i++) 
        {
            int a;
            cin >> a;
            dq.push_back(a);
        }


        for (int i = 0; i < m; i++)
        {
            int q;
            cin  >> q;
            for (int i = 0; i < n; i++)
            {
                if (dq[i] == q)
                {
                    cout << i + 1 << ' ';
                    dq.erase (dq.begin() + i);
                    dq.push_front(q);
                    break;
                }
            }
        }
    }
    
    return 0;
}