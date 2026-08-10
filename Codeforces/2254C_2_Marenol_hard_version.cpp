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
    int n; cin >> n;
    string a, b; cin >> a >> b;

    if (count(all (a), '1') != count(all (b), '1'))
    {
        cout << -1 << endl;
        return;
    }

    int ans = 0;

    vector<int> aeven, aodd, beven, bodd;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            if (i % 2 == 0) aeven.push_back (i);
            else aodd.push_back (i);
        }
        
        if (b[i] == '1')
        {
            if (i % 2 == 0) beven.push_back (i);
            else bodd.push_back (i);
        }
    }


    if (aeven.size() != beven.size() || aodd.size() != bodd.size())
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < aeven.size(); i++)
    {
        ans += abs (aeven[i] - beven[i]);
    }

    for (int i = 0; i < aodd.size(); i++)
    {
        ans += abs (aodd[i] - bodd[i]);
    }

    ans /= 2;
    cout << ans << endl;
}
/*
01001
10010

apos = 1, 4
bpos = 0, 3

1 -> 3 = 2
0 -> 4 = 4

2 6
0 2

0 - 2 = 2
2 - 6 = 4
*/

int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}