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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        string ans1 = "", ans2 = "";
        ll sz = s1.size();
        for (int i = 0; i < sz; i++)
        {
            ans1 += max (s1[i], s2[i]);
            ans2 += min (s1[i], s2[i]);
        }

        int last = 0;

        for (int i = 0; i < sz; i++)
        {
            if (ans1[i] != ans2[i])
            {
                last = i;
                break;
            }
        }

        for (int i = sz-1; i > last; i--)
        {
            if (ans1[i] > ans2[i]) swap(ans1[i], ans2[i]);
        }

        cout << ans1 << endl << ans2 << endl;
    }
    
    return 0;
}