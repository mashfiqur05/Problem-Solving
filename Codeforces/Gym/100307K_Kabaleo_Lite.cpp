///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("kabaleo.in","r",stdin);freopen("kabaleo.out","w",stdout);

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
    int n, p, c, h; cin >> n >> p >> c >> h;
    vector<int> v(n), player (p);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < p; i++) cin >> player[i];

    if (n == 1)
    {
        if (player[p-1] != h) cout << 0 << endl;
        else 
        {
            cout << 1 << endl << 1;
        }
        return;
    }
    map<int, int> frq, pfrq;
    for (auto u : v) frq[u]++;
    for (int i = 1; i < p; i++) pfrq[player[i]]++;

    int top1 = 0, top2 = 0;
    int col1 = 0, col2 = 0;
    for (auto u : frq)
    {
        if (u.first == h) continue;
        if (u.second >= top1)
        {
            top2 = top1;
            top1 = u.second;
            col2 = col1;
            col1 = u.first;
        }
        else if (u.second >= top2) {top2 = u.second; col2 = u.first;}
    }

    int ptop1 = 0, ptop2 = 0;
    int pcol1 = 0, pcol2 = 0;
    for (auto u : pfrq)
    {
        if (u.first == h) continue;
        if (u.second >= ptop1)
        {
            ptop2 = ptop1;
            ptop1 = u.second;
            pcol2 = pcol1;
            pcol1 = u.first;
        }
        else if (u.second >= ptop2) {ptop2 = u.second; pcol2 = u.first;}
    }

    int nonH = 0;
    for (int i = 1; i < p; i++) if (player[i] != h) nonH++;
    // cout << col1 << " " << col2 << " " << ptop1 << " " << ptop2 << endl;
    // cout << "NON H " << nonH << endl;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        frq[v[i]]--;
        frq[player[0]]++;

        // if (i == 0) cout << frq[col1] << " " << frq[col2] << " " << ptop1 << " " << ptop2 << endl;

        int myPoint = max (0LL, frq[h] - nonH);
        int op = max ({frq[col1]+pfrq[col1], frq[col2]+pfrq[col2], ptop1+frq[pcol1], ptop2+frq[pcol2]});

        // if (col1 == pcol1) op = max ({op, frq[col1]+ptop1});
        // if (col1 == pcol2) op = max ({op,frq[col1]+ptop2});
        // if (col2 == pcol1) op = max ({op,frq[col2]+ptop1});
        // if (col2 == pcol2) op = max ({op,frq[col2]+ptop2});
        if (player[0] != h) op = max (op, frq[player[0]]);

        // cout << "i " << i << ": " << myPoint << " " << op << endl;
        if (myPoint > op) ans.push_back (i+1);

        // undo 
        frq[v[i]]++;
        frq[player[0]]--;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}


int32_t main()
{
    fastio();
    // file();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}