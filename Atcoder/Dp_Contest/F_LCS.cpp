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

string s, t; 
int dp[3005][3005];

int fun (int i, int j)
{
    if (i == s.size() || j == t.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) return dp[i][j] = 1 + fun (i+1, j+1);

    return dp[i][j] = max (fun(i+1, j), fun (i, j+1));
}

string get()
{
    string ans = "";

    int i = 0, j = 0;
    while (i < s.size()&& j < t.size())
    {
        if (s[i] == t[j]) 
        {
            ans += s[i];
            i++;
            j++;
        }
        else if (dp[i+1][j] >= dp[i][j+1])
        {
            i++;
        }
        else j++;
    }

    return ans;
}

void solve ()
{
    cin >> s >> t;
    mem (dp, -1);
    fun (0, 0); 

    cout << get() << endl;
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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}