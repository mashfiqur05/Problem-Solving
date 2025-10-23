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
    int n; cin >> n;
    
    vector<int> ans;
    if (n <= 4)
    {
        if (n == 1)
            cout << 1 << endl;
        else if (n <= 3)
            cout << "NO SOLUTION" << endl;
        else if (n == 4)
            cout << "2 4 1 3" << endl;

        return;
    }
    else 
    {
        int even = 2, odd = 1, prev = -1;
        for (int i = 1; i <= n && even <= n && odd <= n; i++)
        {
            int val = min (even, odd);
            if (abs (val - prev) == 1)
            {
                val = max (even, odd);
            }
            prev = val;
            // cout << prev << " ";
            ans.push_back(val);
            if (odd == val)
                odd += 2;
            else
                even += 2;
        }
        while (even <= n)
        {
            ans.push_back(even);
            even += 2;
        }
        while (odd <= n)
        {
            ans.push_back(odd);
            odd += 2;
        }
    }

    for (int i = 0; i < n-1; i++)
    {
        if (abs (ans[i] - ans[(i+1)]) == 1)
        {
            swap (ans[i], ans[i-1]);
        }
    }

    if (n % 5 == 3) swap (ans[n-2], ans[n-4]);
    else if (n % 5 == 4) 
    {
        int a = ans[n-1], b = ans[n-2], c = ans[n-3], d = ans[n-4];
        ans[n-1] = d;
        ans[n-2] = c;
        ans[n-3] = a;
        ans[n-4] = b;
    }

    for (auto x : ans) cout << x << " ";
    cout << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}