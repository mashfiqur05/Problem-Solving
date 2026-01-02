///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

// #define endl '\n'
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


int query (int x, vector<int> v)
{
    cout << "? " << x << " " << v.size() << ' ';
    for (auto u : v) cout << u << ' ';
    cout << endl;

    int ans;
    cin >> ans;
    return ans;
}

void solve (int CaseNo)
{
    int n; cin >> n;
    vector<vector<int>> len (n+1);
    vector<int> v;
    int mx = 0;
    for (int i = 1; i <= n; i++) v.push_back(i);
    dbg (v);
    for (int i = 1; i <= n; i++)
    {
        int val = query (i, v);
        mx = max(mx, val);
        len[val].push_back (i);
    }

    if (mx == 1) 
    {
        cout << "! 1 1" << endl;
        return;
    }

    int cur = len[mx][0];
    vector<int> ans;
    ans.push_back(cur);
    for (int i = mx-1; i >= 1; i--)
    {
        for (auto u : len[i]) 
        {
            int val = query (cur, {cur, u});
            if (val != 1)
            {
                cur = u;
                ans.push_back(cur);
                break;
            }
        }
    }

    cout << "! " << ans.size() << ' ';
    for (auto u : ans) cout << u << ' ';
    cout << endl;
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