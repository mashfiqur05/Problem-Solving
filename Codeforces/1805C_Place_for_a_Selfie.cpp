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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort (all (v));

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int ind = lower_bound (all (v), b) - v.begin();

        // cout << "IND " << ind << endl;

        if (ind < n && sq(v[ind] - b) < 4 * a * c) 
        {
            cout << "YES" << endl << v[ind] << endl;
        }
        else if (ind-1 >= 0 && sq(v[ind-1] - b) < 4 * a * c) 
        {
            cout << "YES" << endl << v[ind-1] << endl;
        }
        else if (ind+1 < n && sq(v[ind+1] - b) < 4 * a * c) 
        {
            cout << "YES" << endl << v[ind+1] << endl;
        }
        else cout << "NO" << endl;
        
        // cout << "VAL " << sq(v[ind-1] - b) << " ANOTHER " << 4 * a * c <<  endl;
    }
    cout << endl;
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