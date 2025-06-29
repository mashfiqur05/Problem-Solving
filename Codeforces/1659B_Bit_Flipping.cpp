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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> ans(n, 0);

    if (k % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && k)
            {
                ans[i] = 1;
                s[i] = '1';
                k--;
            }
        }
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (k)
                {
                    ans[i] = 1;
                    k--;
                }
                else s[i] = '0';
            }
            else s[i] = '1';
        }
    }

    if (k)
    {
        ans[n-1] += k;
        if (k % 2 == 1) 
        {
            if (s[n-1] == '0') s[n-1] = '1';
            else s[n-1] = '0';
        }
    }

    cout << s << endl;
    for (auto u : ans) cout << u << " "; cout << endl;
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