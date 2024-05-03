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
        string s;
        cin >> s;

        ll sz = s.size();
        ll cnt = 0, ans = 0, id = sz;

        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '0') cnt++; /// count '0'
            else 
            {
                id = i; /// 1st '1' jei index e paici oita ber korsi. 
                break;
            }
        }
        //cout << id << endl;

        for (int i = id; i < sz; i++)
        {
            if (s[i] == '0')
            {
                ans += (i - cnt + 1);
                cnt++;
            }
        }

        if (cnt == 0 || cnt == sz) cout << 0 << endl;
        else cout << ans << endl;

        //cout <<cnt << endl;
    }
    
    return 0;
}