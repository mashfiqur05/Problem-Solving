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

bool cmp (pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    if (a.first.first == b.first.first) return a.first.second > b.first.second;
    else return a.first.first < b.first.first;
}

void solve (int CaseNo)
{
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i + 1;
    }

    sort (all (v), cmp);
    
    int ind = -1, r1 = -1;
    for (int i = 0; i < n; i++)
    {
        int r2 = v[i].first.second;
        if (r2 <= r1)
        {
            cout << v[i].second << " " << ind << endl;
            return;
        }
        else 
        {
            r1 = r2;
            ind = v[i].second;
        } 
    }

    cout << "-1 -1" << endl;
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