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
const int N = 2e5+123;
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

set<string> cur;
void allPossibleForY (int pos, string s)
{
    if (pos == s.size()){ cur.insert (s); return;}
    char c = s[pos];
    if (s[pos] == 'y')
    {
        allPossibleForY (pos+1, s);
        s[pos] = 'a';
        allPossibleForY(pos+1, s);
    }
    else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        s[pos] = 'a';
        allPossibleForY(pos+1, s);
    }
    else allPossibleForY (pos+1, s);
}

void solve ()
{
    int n, q; cin >> n >> q;
    map<string, int> cnt;
    map<string, string> track;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        cur.clear();
        allPossibleForY (0, s);
        for (auto u : cur) {cnt[u]++; track[u] = s;}
    }

    // dbg (cnt); dbg(track);
    while (q--)
    {
        int f = 0;
        int w; cin >> w;
        vector<string> ans;
        for (int i = 0; i < w; i++)
        {
            string s; cin >> s;
            if (f != -1 && cnt[s] > 1) f = 2;
            else if (f != 2 && f != -1 && cnt[s] == 1)
            {
                f = 1;
                ans.push_back(track[s]);
            }
            else if (cnt[s] == 0) f = -1;

            // dbg(s, cnt[s], f);
        }

        if (f == 2) cout << "ambiguous" << endl;
        else if (f == -1) cout << "impossible" << endl;
        else 
        {
            cout << "possible" << " ";
            for (auto u : ans) cout << u << " "; cout << endl;
        }
    }
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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}