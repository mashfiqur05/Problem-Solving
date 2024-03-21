#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const ll MX = 123;
//vector<ll> arr(MX);

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n;
        cin >> n;
        string team1 = " ", team2 = " ";
        cin >> team1;

        ll cnt1 = 1, cnt2 = 0;

        for (int i = 1; i < n; i++)
        {
            string s;
            cin >> s;
            if (s == team1)
            {
                cnt1++;
            }
            else 
            {
                team2 = s;
                cnt2++;
            }
        }

        if (cnt1 > cnt2) cout << team1;
        else cout << team2;
        
    }
    
    return 0;
}