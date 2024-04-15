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
        int n, first = 0, last = 0;
        cin >> n;

        vector<int> v(n, 0), arr, s, rev;

        for (int i = 0; i < n; i++) cin >> v[i];

        arr = v;
        sort (all (arr));
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != v[i])
            {
                first = i;
                break;
            }
        }

        for (int i = n-1; i >= 0; i--)
        {
            if (arr[i] != v[i])
            {
                last = i;
                break;
            }
        }

        for (int i = first; i <= last; i++)
        {
            s.push_back (v[i]);
        }

        rev = s;
        sort (all (s));
        reverse(all (rev));

        if (s == rev) cout << "yes" << endl << first+1 << ' ' << last+1;
        else cout << "no" << endl;
    }
    
    return 0;
}   