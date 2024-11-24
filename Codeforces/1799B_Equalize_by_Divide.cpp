///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
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
#define MOD 1000000007
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

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        int mn = *min_element (all (v));
        auto pntr = min_element (all (v));
        int id = distance (v.begin(), pntr);
        // dbg (id);

        if (mn == 1)
        {
            bool ok = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] > 1) {ok = 1; break;}
            }

            if (ok) 
            {
                cout << -1 << endl;
                continue;
            }
        }    

        bool f1 = 1;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != mn) 
            {
                f1 = 0;
                break;
            }
        }
        if (n == 1 || f1) 
        {
            cout << 0 << endl;
            continue;
        }
        vector<pair<int, int>> ans;

        int i = 0;
        while (i < n)
        {
            // if (v[i] == mn) continue;

            while (v[i] > mn)
            {
                ans.push_back ({i+1, id+1});
                v[i] = ceil ((1.00 * v[i]) / (mn * 1.00));
            }

            if (v[i] < mn)
            {
                // dbg (mn, id, v[i], i);
                mn = v[i];
                id = i;
                i = 0;
                // dbg (mn, id, i);
            }
            else i++;
        }

        // dbg (v);
        cout << ans.size() << endl;
        for (auto u : ans) cout << u.first << " " << u.second << endl;
    }

    return 0;
}