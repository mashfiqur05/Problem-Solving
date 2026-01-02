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

int findMinD (vector<int> &v)
{
    sort (all (v));
    int mn = 0;
    for (int i = 0; i+1 < v.size(); i+=2)
    {
        mn = max (mn, v[i+1] - v[i]);
    }

    return mn;
}

void solve (int CaseNo)
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort (all (v));

    if (n == 1) cout << "YES" << endl;
    else if (n % 2 == 0)
    {
        if (findMinD (v) <= d) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> a;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    a.push_back(v[j]);
            }
            if (findMinD(a) <= d)
            {
                cout << "YES" << endl;
                // for (auto u : a) cout << u << " ";
                cout << endl;
                return;
            }
        }

        cout << "NO" << endl;
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