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

//const int MX = 123;
//int arr[MX];

int32_t main()
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

        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
        }

        string r = "";
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i])
            {
                r += (i + 'a');
            }
        }
        string ans = "";
        int sz = r.size();
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (s[i] == r[j])
                {
                    ans += r[sz-j-1];
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}