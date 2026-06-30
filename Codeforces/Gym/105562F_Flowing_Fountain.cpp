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
  
int n, q; 
vector<int> nextGreater, v, ans;

int get(int x) {
    if (x == n + 1) return x;

    if (ans[x] < v[x]) return x;

    return nextGreater[x] = get(nextGreater[x]);
}

void solve ()
{
    cin >> n >> q;
    v.resize(n+2, infLL);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    nextGreater.resize(n+2);
    stack<int> st;

    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && v[st.top()] < v[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nextGreater[i] = n + 1; // ground
        }
        else
        {
            nextGreater[i] = st.top();
        }

        st.push(i);
    }

    // for (int i = 1; i <= n; i++) cout << nextGreater[i] << " ";

    ans.resize(n+2, 0);
    while (q--)
    {
        char c; cin >> c;
        if (c == '+')
        {
            int pot, litre; cin >> pot >> litre;

            int cur = pot, rem = litre;
            while (cur <= n && ans[cur] + rem > v[cur])
            {
                int canbare = v[cur] - ans[cur];
                rem -= canbare;
                ans[cur] = v[cur];
                cur = nextGreater[cur];

                if (ans[cur] == v[cur])
                {
                    nextGreater[cur] = get(nextGreater[cur]);
                }
            }
            if (cur <= n) ans[cur] += rem;
        }
        else 
        {
            int pot; cin >> pot; 
            cout << ans[pot] << endl;
        }
    }
}

int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}