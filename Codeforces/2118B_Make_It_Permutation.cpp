///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freuen("input.txt","r",stdin);freuen("output.txt","w",stdout);

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
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<tuple<int, int, int>> ans;

    ans.push_back (make_tuple (1, 1, n));
    for (int i = 1; i < n; ++i)
    {
        // for (int j = 0; j < n; ++j)
        // {
        //     matrix[i][j] = (i + j) % n + 1;
        // }

        ans.push_back (make_tuple (i+1, 1, n-i));
        ans.push_back (make_tuple (i+1, n-i+1, n));
    }

    // Output uerations
    cout << ans.size() << endl;
    for (auto &u : ans)
    {
        cout << get<0>(u) << ' ' << get<1>(u) << ' ' << get<2>(u) << endl;
    }

    // cout << "Final Matrix:" << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases(tt);
    }

    return 0;
}