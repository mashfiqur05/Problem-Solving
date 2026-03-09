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
    int n, m; cin >> n >> m;
    priority_queue<int> a, b;

    for (int i = 0; i < n; i++) 
    {
        int v; cin >> v;
        a.push (v);
    }
    for (int i = 0; i < m; i++) 
    {
        int v; cin >> v;
        b.push (v);
    }

    int turn = 1;
    while (!a.empty() && !b.empty())
    {
        if (turn == 1)
        {
            int p = a.top(), q = b.top();
            b.pop();

            if (p < q)
            {
                b.push (q - p);
            }
            turn = 2;
        }
        else
        {
            int p = b.top(), q = a.top();
            a.pop();

            if (p < q)
            {
                a.push (q - p);
            }
            turn = 1;
        }
    }

    if (a.empty()) cout << "Bob" << endl;
    else cout << "Alice" << endl;
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