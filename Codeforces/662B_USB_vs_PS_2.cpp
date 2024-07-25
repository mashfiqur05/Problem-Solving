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
        ll usb, ps, both, m;
        cin >> usb >> ps >> both >> m;
        vector<pair<ll, string>> p;

        for (int i = 0; i < m; i++)
        {
            int a;
            string s;
            cin >> a >> s;
            p.push_back ({a, s});
        }

        sort (all (p));
        ll cost = 0, pc = 0;

        for (int i = 0; i < m; i++)
        {
            if (p[i].second == "USB" && usb)
            {
                cost += p[i].first;
                usb--;
                pc++;
            }
            else if (p[i].second == "PS/2" && ps) 
            {
                cost += p[i].first;
                ps--;
                pc++;
            }   
            else if (both)
            {
                cost += p[i].first;
                both--;
                pc++;
            }
        }

        cout << pc << " " << cost << endl;
    }
    
    return 0;
}