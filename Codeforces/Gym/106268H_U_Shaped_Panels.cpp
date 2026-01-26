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
const int MX = 2e5 + 123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9 + 7;

void solve(int CaseNo)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];

    bool f = true;

    for (int i = n - 1; i >= 0 && f; i--)
    {
        for (int j = m - 1; j >= 0 && f; j--)
        {
            if (v[i][j] == '.')
                continue;

            bool removed = false;

            vector<pair<int, int>> corners = {
                {i, j},                
                {i - k + 1, j},        
                {i, j - k + 1},        
                {i - k + 1, j - k + 1} 
            };

            for (auto u : corners)
            {
                int x = u.first, y = u.second;
                if (x < 0 || y < 0 || x + k - 1 >= n || y + k - 1 >= m)
                    continue;

                if (v[x][y] != '#' ||
                    v[x + k - 1][y] != '#' ||
                    v[x][y + k - 1] != '#' ||
                    v[x + k - 1][y + k - 1] != '#')
                    continue;

                bool top = true, bottom = true, left = true, right = true;

                for (int t = 0; t < k; t++)
                {
                    if (v[x][y + t] != '#')
                        top = false;
                    if (v[x + k - 1][y + t] != '#')
                        bottom = false;
                    if (v[x + t][y] != '#')
                        left = false;
                    if (v[x + t][y + k - 1] != '#')
                        right = false;
                }

                int fullSides = top + bottom + left + right;

                if (fullSides != 3)
                    continue;

                v[x][y] = v[x + k - 1][y] = v[x][y + k - 1] = v[x + k - 1][y + k - 1] = '.';

                if (top)
                {
                    for (int t = 1; t < k - 1; t++)
                        v[x][y + t] = '.';
                }
                if (bottom)
                {
                    for (int t = 1; t < k - 1; t++)
                        v[x + k - 1][y + t] = '.';
                }
                if (left)
                {
                    for (int t = 1; t < k - 1; t++)
                        v[x + t][y] = '.';
                }
                if (right)
                {
                    for (int t = 1; t < k - 1; t++)
                        v[x + t][y + k - 1] = '.';
                }

                removed = true;
                break;
            }

            if (!removed)
            {
                f = false;
            }
        }
    }

    cout << (f ? "yes\n" : "no\n");
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