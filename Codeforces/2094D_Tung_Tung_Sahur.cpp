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
    string p, s;
    cin >> p >> s;
    vector<int> block_p, block_s;
    vector<char> cp, cs;
    if (p == s)
    {
        cout << "YES" << endl;
        return;
    }
    int cnt = 1;
    for (int i = 0; i < p.size() - 1; i++)
    {
        if (p[i] == p[i+1]) cnt++;
        else 
        {
            block_p.push_back (cnt);
            cp.push_back (p[i]);
            cnt = 1;
        }
    }
    block_p.push_back (cnt);
    cp.push_back (p[p.size()-1]);
    // dbg (cnt);

    cnt = 1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i+1]) cnt++;
        else 
        {
            block_s.push_back (cnt);
            cs.push_back (s[i]);
            cnt = 1;
        }
    }
    block_s.push_back (cnt);
    cs.push_back (s[s.size()-1]);
    // dbg (cnt);
    // dbg (block_p, block_s);

    for (int i = 0; i < min (block_p.size(), block_s.size()); i++)
    {
        if (block_s[i] >= block_p[i] && block_s[i] <= 2*block_p[i]  && cp[i] == cs[i]){}
        else 
        {
            cout << "NO" << endl;
            return;
        }
    }

    if (block_s.size() != block_p.size()) cout << "NO" << endl;
    else cout << "YES" << endl;
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