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
    vector<int> b(n), a(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> cnt;
    for (auto u : b) cnt[u]++;
    vector<int> tmp;
    for (auto u : cnt) tmp.push_back (u.first);
    map<int, int> ans;

    if (tmp[0] != 0)
    {
        cout << -1 << endl;
        return;
    }

    // bool f = 1;
    int sum = 0, cur = 1;
    for (int i = 0; i < tmp.size(); i++)
    {
        int val = tmp[i], curValAce = cnt[val];
        int nxtBoro = (i != tmp.size()-1 ? tmp[i+1] : -1);

        if (nxtBoro == -1) 
        {
            ans[val] = cur;
            continue;
        }
        int rem = nxtBoro - sum;
        if (rem % curValAce != 0 || (rem / curValAce) < cur)
        {
            cout << -1 << endl;
            return;
        }

        // cout << val << " " << curValAce << " " << rem << endl;
        ans[val] = rem / curValAce;
        cur = ans[val] + 1;
        sum += (ans[val] * curValAce);
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = ans[b[i]];
        cout << a[i] << " ";
    }
    cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     int ind = b[i].second, val = b[i].first;
    //     int nxtBoro = (pos < tmp.size() ? tmp[pos] : -1); 

    //     int curValAce = cnt[val], rem = nxtBoro - sum;
    //     if (rem % curValAce != 0)
    //     {
    //         cout << -1 << endl;
    //         return;
    //     } 
    //     a[ind] = rem/curValAce;

    // }
}

/*
0 0 4 4 14
2 2 5 5

0 4 4 4 4 4 9
4 
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