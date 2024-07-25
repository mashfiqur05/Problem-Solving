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
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        int sz = s.size();

        for (int i = 0; i < sz; i++)
        {
            cnt[s[i] - 'a']++;
        }

        char ch;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] % 2 == 1)
            {
                bool f = 0;
                for (int j = 25; j > i; j--)
                {
                    if (cnt[j] % 2 == 1)
                    {
                        cnt[i]++;
                        cnt[j]--;
                        f = 1;
                        break;
                    }
                }

                if (!f) 
                {
                    ch = ('a' + i);
                    break;
                }
            }
        }

        string ans = "";
        for (int i = 0; i < 26; i++)
        {
            int tmp = cnt[i] / 2;
            while (tmp--)
            {
                ans += ('a' + i);
            }
        }
        
        //cout << ch << endl;
        cout << ans;
        if (sz % 2 == 1) cout << ch;
        reverse (all (ans));
        cout << ans;
    }
    
    return 0;
}