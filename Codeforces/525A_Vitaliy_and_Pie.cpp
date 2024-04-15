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

const ll MX = 123;
int cnt[MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        string s;
        cin >> n >> s;

        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
            {
                cnt[s[i] - 'a']++;
            }
            else 
            {
                int tmp = tolower(s[i]) - 'a';
                if (cnt[tmp])
                {
                    cnt[tmp]--;
                }
                else ans++;
            }
        }

        cout << ans << endl;
        /*for (int i = 0; i < 26; i++)
        {
            cout << cnt[i] << ' ';
        }*/
    }
    
    return 0;
}