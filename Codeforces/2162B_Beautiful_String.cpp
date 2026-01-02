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

bool isPalindrome(string &t)
{
    for (int i = 0, j = (int)t.size() - 1; i < j; i++, j--)
    {
        if (t[i] != t[j])
            return false;
    }
    return true;
}

bool nondecreasing(string &p)
{
    for (int i = 1; i < (int)p.size(); i++)
    {
        if (p[i] < p[i - 1])
            return false;
    }
    return true;
}

void solve(int CaseNo)
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool found = false;
    vector<int> ans;
    int total = 1 << n;
    for (int mask = 0; mask < total; mask++)
    {
        string p = "", x = "";
        vector<int> idx;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                p += s[i];
                idx.push_back(i + 1);
            }
            else
                x += s[i];
        }
        if (nondecreasing(p) && isPalindrome(x))
        {
            ans = idx;
            found = true;
            break;
        }
    }
    if (!found) cout << -1 << endl;
    else
    {
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
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
        solve (tt);
    }

    return 0;
}