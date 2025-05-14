///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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


void testCases (int tt)
{
    string s;
    cin >> s;

    int hour = (s[0] - '0') * 10 + (s[1] - '0'), min = (s[3] - '0') * 10 + (s[4]-'0'), ans = 0;
    while (1)
    {
        string h = to_string (hour), m = to_string (min);
        if (h.size() == 1) h = '0' + h;
        if (m.size() == 1) m = '0' + m;
        reverse (all (m));
        if (h == m)
        {
            // cout << hour << " " << min << endl;
            cout << ans << endl;
            return;
        }

        ans++;
        min = (min + 1);
        if (min >= 60)
        {
            min %= 60;
            hour = (hour + 1) % 24;
        }

        // cout << ans << " " << h <<" " << m << endl;
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}