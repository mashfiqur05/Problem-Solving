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
    int n, m, k; cin >> n >> m >> k;

    vector<pair<int, int>> ans;
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= m; j++)
            {
                if (k != 1) 
                {
                    if (f)
                    {
                        cout << 2 << " " << i << " " << j << " ";
                        f = 0;
                    }
                    else 
                    {
                        cout << i << " " << j << endl;
                        k--;
                        f = 1;
                    }
                }
                else 
                {
                    ans.push_back ({i, j});
                }
            }
        }
        else
        {
            for (int j = m; j >= 1; j--)
            {
                if (k != 1) 
                {
                    if (f)
                    {
                        cout << 2 << " " << i << " " << j << " ";
                        f = 0;
                    }
                    else 
                    {
                        cout << i << " " << j << endl;
                        k--;
                        f = 1;
                    }
                }
                else 
                {
                    ans.push_back ({i, j});
                }
            }
        }
    }

    cout << ans.size() << " ";
    for (auto u : ans) cout << u.first <<" " << u.second << " ";
    cout << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}