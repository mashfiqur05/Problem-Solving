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


void testCases (int tt)
{
    int n;
    cin >> n;
    vector<int> row(n), col(n);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> row[i] >> col[i];
        v[i] = {row[i], col[i]};
    }
    sort (all (v));
    sort (all (row));
    sort (all (col));

    // dbg (v);dbg (row); dbg (col);
    if (n == 1) 
    {
        cout << 1 << endl;
        return;
    }

    int ans = infLL;

    for (int i = 0; i < n; i++)
    {
        int x = v[i].first, y = v[i].second;
        int mnx = row[0], mxx = row[n-1], mny = col[0], mxy = col[n-1];
        if (x == mnx) mnx = row[1];
        if (x == mxx) mxx = row[n-2];
        if (y == mny) mny = col[1];
        if (y == mxy) mxy = col[n-2];

        int res = (mxx - mnx + 1) * (mxy - mny + 1);
        // dbg (mxx, mnx, mxy, mny);
        // dbg ((mxx - mnx + 1)); dbg ( (mxy - mny + 1));
        // dbg (res);
        if (res >= n) ans = min (ans, res);
        else 
        {
            res += min ((mxx - mnx + 1), (mxy - mny + 1));
            ans = min (ans, res);
        }
    }

    cout << ans << endl;
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