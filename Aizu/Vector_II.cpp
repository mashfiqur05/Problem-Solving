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

const int MX = 1123;
vector<int> v[MX];
//int arr[MX];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, q; cin >> n >> q;

        while (q--)
        {
            int op;
            cin >> op;
            if (op == 0)
            {
                int t, x;
                cin >>  t >> x;
                v[t].push_back (x);
            }
            else if (op == 1)
            {
                int t;
                cin >> t;

                for(int i=0; i<v[t].size(); i++)
                {
                    cout << v[t][i];
                    if(i != v[t].size()-1)
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            else 
            {
                int t;
                cin >> t;
                v[t].clear();
            }
        }
    }
    
    return 0;
}