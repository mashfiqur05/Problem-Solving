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

//const int mx = 123;
//int arr[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            if ((s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e')) 
            {
                ans++;
                i += 2;
            }
            if (s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p')
            {
                ans++;
                i += 2;
            }
        }

        cout << ans << endl;    
    }
    
    return 0;
}