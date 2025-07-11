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
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> b[i][j];
    }

    if (n == 1 || m == 1)
    {
        cout << "YES" << endl;
        return; 
    }
    
    vector<vector<int>> rows_a, rows_b, col_a, col_b;

    for (int i = 0; i < n; i++)
    {
        vector<int> tmp1, tmp2;
        for (int j = 0; j < m; j++) 
        {
            tmp1.push_back (a[i][j]);
            tmp2.push_back (b[i][j]);
        }

        sort (all (tmp1));
        sort (all (tmp2));
        rows_a.push_back (tmp1);
        rows_b.push_back (tmp2);
    }

    for (int j = 0; j < m; j++)
    {
        vector<int> tmp1, tmp2;
        for (int i = 0; i < n; i++)
        {
            tmp1.push_back (a[i][j]);
            tmp2.push_back (b[i][j]);
        }

        sort (all (tmp1));
        sort (all (tmp2));
        col_a.push_back (tmp1);
        col_b.push_back (tmp2);
    }

    sort (all (rows_a));
    sort (all (rows_b));
    sort (all (col_a));
    sort (all (col_b));

    for (int i = 0; i < rows_a.size(); i++)
    {
        if (rows_a != rows_b)
        {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 0; i < col_a.size(); i++)
    {
        if (col_a != col_b)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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