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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int tot = (accumulate(all(a), 0LL) + 2) / 3;
    // cout << tot << endl;
    vector<tuple<int, int, int>> order;
    order.push_back({0, 1, 2});
    order.push_back({0, 2, 1});
    order.push_back({1, 0, 2});
    order.push_back({1, 2, 0});
    order.push_back({2, 0, 1});
    order.push_back({2, 1, 0});

    for (auto [x, y, z] : order)
    {
        vector<pair<int, int>> res(3, {0, 0});
        bool f = 1;
        // 1st
        int sum = 0, i = 0;
        if (x == 0)
        {
            res[0].first = 1;
            while (i < n && sum < tot)
            {
                sum += a[i];
                i++;
            }
            res[0].second = i;
        }
        else if (x == 1)
        {
            res[1].first = 1;
            while (i < n && sum < tot)
            {
                sum += b[i];
                i++;
            }
            res[1].second = i;
        }
        else
        {
            res[2].first = 1;
            while (i < n && sum < tot)
            {
                sum += c[i];
                i++;
            }
            res[2].second = i;
        }
        if (sum < tot) f = 0;
        
        // 2nd
        sum = 0;
        if (y == 0)
        {
            res[0].first = i+1;
            while (i < n && sum < tot)
            {
                sum += a[i];
                i++;
            }
            res[0].second = i;
        }
        else if (y == 1)
        {
            res[1].first = i+1;
            while (i < n && sum < tot)
            {
                sum += b[i];
                i++;
            }
            res[1].second = i;
        }
        else
        {
            res[2].first = i+1;
            while (i < n && sum < tot)
            {
                sum += c[i];
                i++;
            }
            res[2].second = i;
        }
        if (sum < tot) f = 0;

        //3rd 
        sum = 0;
        if (z == 0)
        {   
            res[0].first = i+1;
            while (i < n && sum < tot)
            {
                sum += a[i];
                i++;
            }
            res[0].second = i;
        }
        else if (z == 1)
        {
            res[1].first = i+1;
            while (i < n && sum < tot)
            {
                sum += b[i];
                i++;
            }
            res[1].second = i;
        }
        else
        {
            res[2].first = i+1;
            while (i < n && sum < tot)
            {
                sum += c[i];
                i++;
            }
            res[2].second = i;
        }
        if (sum < tot) f = 0;
        
        for (auto u : res)
        {
            if (u.first == 0 || u.second == 0)
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            for (auto u : res)
                cout << u.first << " " << u.second << " "; 
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
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
        cin >> testcases;
        for (int tt = 1; tt <= testcases; tt++)
        {
            solve();
        }

        return 0;
    }