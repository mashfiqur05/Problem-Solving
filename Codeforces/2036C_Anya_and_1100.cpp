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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }

bool isHere(const string &s, int pos)
{
    return pos >= 0 && pos + 3 < s.size() && s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0';
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        int q;
        cin >> q;
        int cnt = 0;
        for (int i = 0; i < sz(s) - 3; i++)
        {
            if (isHere (s, i)) cnt++;
        }

        while (q--)
        {
            int id, val;
            cin >> id >> val;
            id--;

            for (int i = id - 3; i <= id; i++) 
            {
                if (isHere(s, i)) cnt--;
            }

            s[id] = '0' + val;

            for (int i = id - 3; i <= id; i++) 
            {
                if (isHere(s, i)) cnt++;
            }

            if (cnt) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}