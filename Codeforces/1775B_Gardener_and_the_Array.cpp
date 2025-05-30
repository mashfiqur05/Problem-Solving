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
const int MX = 1e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void testCases (int tt)
{
    int n;
    cin >> n;
    unordered_map<int, int> vis;
    bool f = true, ans = 0;
    vector<pair<int, vector<int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        for (int j = 0; j < v[i].first; j++) 
        {
            int c;
            cin >> c;
            v[i].second.push_back (c);
            vis[c]++;
            // cout << c << " " << vis[c] << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        f = true;
        for (int j = 0; j < v[i].first; j++)
        {
            int p = v[i].second[j];
            if (f)
            {
                if (vis[p] >= 2) continue;
                else {f = false; break;}
            }
        }
        if (f)
        {
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}