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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve (int testCase)
{
    int n;
    cin >> n;
    map<int, vector<int>> city;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        city[a].push_back (b);
        city[b].push_back (a);
    }

    // for (const auto& entry : city)
    // {
    //     cout << "City " << entry.first << ": ";
    //     for (const auto& neighbor : entry.second)
    //     {
    //         cout << neighbor << " ";
    //     }
    //     cout << endl;
    // }

    int st = -1;
    for (auto entry : city)
    {
        if (entry.second.size() == 1)
        {
            st = entry.first;
            break;
        }
    }

    vector<int> ans;
    ans.push_back (st);
    // cout << st << " " << city[st].size() << endl;
    // if (city[st][0] == st) st = city[st][1];
    // else st = city[st][0];
    int prev = -1; // Previous node tracker
    while (city[st].size() > 1 || ans.size() < city.size())
    {
        int next_st = -1;

        // Find the next node that's not the previous node
        for (int neighbor : city[st])
        {
            if (neighbor != prev)
            {
                next_st = neighbor;
                break;
            }
        }

        if (next_st == -1) break; // No valid next node found

        ans.push_back(next_st);
        prev = st; // Update the previous node
        st = next_st; // Move to the next node
    }


    for (auto u : ans) cout << u << " "; cout << endl;
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