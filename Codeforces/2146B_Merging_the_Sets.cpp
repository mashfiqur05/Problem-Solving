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

/*
m = 3
A te full ace. taile r 2 ta thakle sure

5 10
a 1 2 3 4 
b 1 2 5 6 7
c 2 6 7 8 9
d 6 7 8 9
e 9 10

kono element just ekbar thakle oita must include korte hobe.
e+a+b+c = 1 2 3 4 9 10 5 6 7
e+a+b+d = 1 2 3 4 9 10 5 6 7
e+a+b+c+d =1 2 3 4 9 10 5 6 7
*/
void solve ()
{
    int n, m; cin >> n >> m;
    vector<int> pos[m+1];
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int l;cin >> l;
        vector<int> tmp(l);
        for (int j = 0; j < l; j++)
        {
            cin >> tmp[j];
            pos[tmp[j]].push_back (i);
        }
        v.push_back(tmp);
    }

    set<int> mustNeed;
    for (int i = 1; i <= m; i++)
    {
        if (pos[i].size() == 0)
        {
            cout << "NO" << endl;
            return;
        }

        if (pos[i].size() == 1)
        {
            mustNeed.insert(pos[i][0]);
        }
    }

    if (sz(mustNeed)+2 <= n) cout << "YES" << endl;
    else cout << "NO" << endl;
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