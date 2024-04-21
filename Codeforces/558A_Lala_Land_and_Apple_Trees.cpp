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
        int n;
        cin >> n;
        vector<pair<int, int>> pos, neg;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a < 0) neg.push_back ({a, b});
            else pos.push_back ({a, b});
        }

        sort (rall (neg));
        sort (all (pos));

        int total = 0;

        int mn = min (neg.size(), pos.size());

        for (int i = 0; i <= mn; i++)
        {
            if (pos.size() > i) total += pos[i].second;
            if (neg.size() > i) total += neg[i].second;
        }

        cout << total << endl;
    }
    
    return 0;
}