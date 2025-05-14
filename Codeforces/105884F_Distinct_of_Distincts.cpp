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


void testCases (int tt)
{
    int n, m;
    cin >> n >> m;
    int mn = min (n, m);
    int ans[n][m];

    for (int i = 0; i < mn; i++)
    {   
        int val = 1;
        for (int j = 0; j <= i; j++)
        {
            ans[i][j] = val;
        }
        val++;
        for (int j = i+1; j < mn; j++)
        {
            ans[i][j] = val++;
        }
    }

    if (n > m)
    {
        for (int i = mn; i < n; i++)
        {
            int val = i+1;
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = val;
            }
        }
    }
    else if (m > n)
    {
        for (int j = mn; j < m; j++)
        {
            int val = j + 1;
            for (int i = 0; i < n; i++) ans[i][j] = val;
        }
    }

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        set<int> tmp;
        for (int j = 0; j < m; j++) tmp.insert(ans[i][j]);
        s.insert (tmp.size());
    }

    for (int j = 0; j < m; j++)
    {
        set<int> tmp;
        for (int i = 0; i < n; i++)tmp.insert(ans[i][j]);
        s.insert (tmp.size());
    }

    cout << s.size() << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cout << ans[i][j] << " ";
        cout << endl;
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
        testCases (tt);
    }

    return 0;
}