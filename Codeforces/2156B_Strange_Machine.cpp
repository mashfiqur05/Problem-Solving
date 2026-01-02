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


void solve (int CaseNo)
{
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    vector<int> query (q);
    for (int i = 0; i < q; i++) cin >> query[i];

    vector<int> val;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) 
        {
            val.push_back (s[i] == 'A' ? -1 : 2);
        }
        else if (s[i] == 'A' && s[i-1] == 'A') val[val.size() - 1]--;
        else if (s[i] == 'A') val.push_back (-1);
        else val.push_back (2);
    }

    int cnt = count (all (s), 'A');
    for (int i = 0; i < q; i++)
    {
        int ans = 0;
        int a = query[i];
        if (cnt == n)
        {
            ans = (a / cnt) * val[0] * (-1);
            ans += a % cnt;
            cout << ans << endl;
            continue;
        }

        int id = 0;
        while (a)
        {
            if (val[id] == 2)
            {
                a /= 2;
                ans++;
            }
            else
            {
                if (a + val[id] >= 0)
                {
                    a += val[id];
                    ans -= val[id];
                }
                else
                {
                    ans += a;
                    a = 0;
                }
            }

            id++;
            if (id == val.size()) id = 0;
        }
        cout << ans << endl;
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}