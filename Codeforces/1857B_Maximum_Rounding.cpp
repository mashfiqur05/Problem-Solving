///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve ()
{
    string s;
    cin >> s;
    s = '0' + s;
    // cout << s << endl;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]-'0' < 5) ans += s[i];
        else 
        {
            for (int j = i-1; j >= 0; j--)
            {
                if (ans[j]-'0' <= 3)
                {
                    // cout << ++ans[j] << endl;
                    ans[j]++;
                    break;
                }
                else ans[j] = '0';
            }
            for (int j = i; j < s.size(); j++) ans += '0';
            break;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0 && ans[0] == '0')
            continue;
        cout << ans[i];
    }
    cout << endl;
}

int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}