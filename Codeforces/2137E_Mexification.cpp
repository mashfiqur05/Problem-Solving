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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    map<int, int> frq;
    for (int i = 0; i < n; i++) frq[v[i]]++;

    int mex = 0;
    for (auto u : frq)
    {
        if (u.first == mex) mex++;
        else if (u.first > mex) break;
    }

    vector<vector<int>> ans;
    while (1)
    {
        vector<int> cur(n);
        for (int i = 0; i < n; i++)
        {
            if (v[i] > mex) {cur[i] = mex; v[i] = mex;}
            else 
            {
                if (frq[v[i]] > 1) {cur[i] = mex; v[i] = mex;}
                else cur[i] = v[i];
            }
        }

        // for (auto u : cur) cout << u << " "; cout << endl;

        ans.push_back(cur);
        frq.clear();
        mex = 0;
        for (auto u : cur) frq[u]++;
        // cout << "Frq " << endl;
        for (auto u : frq)
        {
            if (u.first == mex) mex++;
            else if (u.first > mex) break;
            // cout << u.first << " " << u.second << endl;
        }
        // cout << "Mex -->> " << mex << endl;
        if (ans.size() >= 3) break;
    }
    
    vector<int> final;
    if (k <= 3) final = ans[k-1];
    else if (ans[0] == ans[2])
    {
        if (k % 2 == 1) final = ans[0];
        else final = ans[1];
    }
    else 
    {
        if (k % 2 == 1) final = ans[2];
        else final = ans[1];
    }

    int sum = accumulate(all(final), 0LL);

    cout << sum << endl;
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