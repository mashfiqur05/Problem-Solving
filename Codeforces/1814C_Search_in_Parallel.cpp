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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> v[i].first;
        v[i].second = i+1;
    }

    sort (rall (v));

    vector<int> a, b;
    int t1 = s1, t2 = s2;
    for (int i = 0; i < n; i++)
    {
        int ind = v[i].second;
        if (t1 < t2)
        {
            a.push_back (ind);
            t1 += s1;
        }
        else 
        {
            b.push_back (ind);
            t2 += s2;
        }
    }

    cout << a.size() << " ";
    for (auto u : a) cout << u << " "; cout << endl;
    cout << b.size() << " ";
    for (auto u : b) cout << u << " "; cout << endl;
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