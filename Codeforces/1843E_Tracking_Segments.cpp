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

//
//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

bool isPossible (int n, vector<pair<int, int>> &v, vector<int> &b, int mid)
{
    vector<int> a(n+1, 0);
    for (int i = 0; i < mid; i++)
    {
        a[b[i]] = 1;
    }

    // dbg(mid);
    // dbg(a);
    for (int i = 1; i <= n; i++) a[i] += a[i-1];
    
    // dbg(a);
    for (auto u : v)
    {
        int l = u.first, r = u.second;
        int len = (r-l+1);
        int ones = (l == 0 ? a[r] : a[r] - a[l-1]);
        int zero = len - ones;
        // dbg(l, r, len, zero, ones);
        if (ones > zero) return true;
    }

    return false;
}

void solve ()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
    int q; cin >> q;
    vector<int> b(q);
    for (int i = 0; i < q; i++) cin >> b[i];

    bool f = isPossible (n, v, b, q);
    if (!f)
    {
        cout << -1 << endl;
        return;
    }

    int l = 0, r = q, ans = r;;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isPossible(n, v, b, mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else l = mid+1;
    }

    cout << ans << endl;
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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}