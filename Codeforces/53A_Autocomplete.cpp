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
        string s;
        int n;
        cin >> s >> n;
        int sz = s.size();

        vector<string> v;
        for (int i = 1; i <= n; i++)
        {
            string x;
            cin >> x;
            int cnt = 0;
            for (int i = 0; i < sz; i++)
            {
                if (s[i] == x[i]) cnt++;
            }

            if (sz == cnt) v.push_back (x);
        }

        if (v.size() == 0) cout << s;
        else
        {
            sort (all (v));
            cout << v[0];
        }
    }
    
    return 0;
}