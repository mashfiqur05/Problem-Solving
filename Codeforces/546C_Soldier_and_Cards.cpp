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
    deque<int> a, b;
    map<int, int> frq;
    bool f = true;
    int ans = 0;
    int p, q; cin >> p;
    for (int i = 0; i < p; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x; cin >> x;
        b.push_back(x);
    }

    while (!a.empty() && !b.empty())
    {
        if (a.front () > b.front())
        {
            a.push_back (b.front());
            a.push_back (a.front());
            frq[a.front()]++;
            frq[b.front()]++;

            a.pop_front();
            b.pop_front();
        }
        else if (b.front() > a.front())
        {
            b.push_back (a.front());
            b.push_back (b.front());
            frq[a.front()]++;
            frq[b.front()]++;

            a.pop_front();
            b.pop_front();
        }
        ans++;
        if (ans > MX) 
        {
            f = 0; break;
        }
    }

    if (f)
    {
        cout << ans << " " << (a.empty() ? 2 : 1) << endl;
    }
    else cout << -1 << endl;
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