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


void solve ()
{
    int n; cin >> n;
    vector<int> b(n), pos, zero;
    multiset<int> neg;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] > 0)pos.push_back (b[i]);
        else if (b[i] == 0) zero.push_back (b[i]);
        else neg.insert((-1)*b[i]);
    }

    sort (all (pos));

    if(pos.empty())
    {
        cout << -1 << endl;
        return;
    }

    // dbg(pos, neg, zero.size());

    vector<int> ans(n, -1);
    int cur = pos[0], pi = 1, ni = 0, zi = 0;
    ans[0] = cur;
    for (int i = 1; i < n; i++)
    {
        // cout << cur << " ";
        if (!neg.empty() && cur > *neg.begin())
        {
            auto it = neg.lower_bound(cur);
            it--;
            cur -= *it;
            neg.erase(it);
            ans[i] = cur;
        }
        else if (zi < zero.size() && cur > 0)
        {
            ans[i] = cur;
            zi++;
        }
        else if (pi < pos.size()) 
        {
            cur += pos[pi];
            ans[i] = cur;
            pi++;
        }

        // cout << ans[i] << endl;

        if (ans[i] == -1)
        {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
}

/*
-2 -2 4 1 0 1
1 1 4   0 -2 -2
1 1 2 6 4 2
*/
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