
///   ***   ---   |||          In the name of ALLAH          |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()

void solve()
{
    int n; cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> diff(n-1);

    int mx = -1;
    vector<int> pos;

    for (int i = 0; i < n-1; i++)
    {
        diff[i] = abs(v[i] - v[i+1]);

        if(diff[i] > mx)
        {
            mx = diff[i];
            pos.clear();
            pos.push_back(i);
        }
        else if(diff[i] == mx)
            pos.push_back(i);
    }

    if (sz(pos) >= 3)
    {
        cout << mx << endl;
        return;
    }

    vector<int> pref(n-1), suff(n-1);

    pref[0] = diff[0];

    for (int i = 1; i < n-1; i++)
        pref[i] = max(pref[i-1], diff[i]);

    suff[n-2] = diff[n-2];

    for (int i = n-3; i >= 0; i--)
        suff[i] = max(suff[i+1], diff[i]);

    int ans = mx;

    if(sz(pos) == 2)
    {
        int i = pos[0];
        int j = pos[1];

        int inside = 0;

        for(int k = i+1; k < j; k++)
            inside = max(inside, diff[k]);

        int res = 2 * inside;

        if(i > 0)
            res = max(res, pref[i-1]);

        if(j < n-2)
            res = max(res, suff[j+1]);

        res = max({res,
                   abs(v[i] - 2 * v[j]),
                   abs(2 * v[i + 1] - v[j + 1])});
        ans = min(ans, res);
    }
    else
    {
        int i = pos[0];

        int inside = 0;

        for(int j = i; j >= 0; j--)
        {
            if(j < i) inside = max(inside, diff[j]);

            int res = 2 * inside;

            if(j > 1)
                res = max(res, pref[j-2]);

            if(i < n-2)
                res = max(res, suff[i+1]);

            if(j > 0)
                res = max(res, abs(v[j-1] - 2*v[i]));

            if(i < n-1)
                res = max(res, abs(2*v[j] - v[i+1]));

            ans = min(ans, res);
        }

        inside = 0;

        for(int j = i+1; j < n; j++)
        {
            if(j > i+1)
                inside = max(inside, diff[j-1]);

            int res = 2 * inside;

            if(i > 0)
                res = max(res, pref[i-1]);

            if(j < n-2)
                res = max(res, suff[j+1]);

            res = max(res, abs(v[i] - 2*v[j]));

            if(j < n-1)
                res = max(res, abs(2*v[i+1] - v[j+1]));

            ans = min(ans, res);
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    fastio();

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
