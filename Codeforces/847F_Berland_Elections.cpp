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

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int>&b)
{
    if (a.first.first == b.first.first) return a.first.second < b.first.second;
    return a.first.first > b.first.first;
}

void solve (int CaseNo)
{
    int n, k, m, a; cin >> n >> k >> m >> a;
    vector<int> lastTimeVote (n+1, inf);
    map<int, int> frq;
    for (int i = 1; i <= n; i++) frq[i] = 0;
    for (int i = 0; i < a; i++)
    {
        int vote; cin >> vote;
        frq[vote]++;
        lastTimeVote[vote] = i;
    }

    int remain = m-a;
    vector<pair<pair<int, int>, int>> v;
    for (int i = 1; i <= n; i++) v.push_back ({{frq[i], lastTimeVote[i]}, i});
    sort (all (v), cmp);

    // dbg (v);
    // dbg (frq);

    for (int i = 1; i <= n; i++)
    {

        if (frq[i] == 0 && remain == 0)
        {
            cout << 3 << " "; continue;
        }
        if (k >= sz(v) && frq[i] > 0)
        {
            cout << 1 << " "; continue;
        }
        // case 1: guarrenty
        int needToOut = 0;
        bool inK = false;
        for (int j = 0; j <= k; j++)
        {
            int curVote = v[j].first.first, time = v[j].first.second, candid = v[j].second;
            if (candid == i && frq[candid] > 0) inK = true;
            else if (inK)
            {
                needToOut += (frq[i] - curVote + 1);
            }
        }

        // cout << i << " " << needToOut << " " << remain << endl;
        if (remain < needToOut && inK)
        {
            cout << 1 << " "; continue;
        }

        // for case 3: not possible.
        
        
        vector<pair<pair<int, int>, int>> tmp = v;
        for (int j = 0; j < sz(tmp); j++)
        {
            int curVote = tmp[j].first.first, time = tmp[j].first.second, candid = tmp[j].second;
            if (candid == i)
            {
                tmp[j].first.first += remain;
                tmp[j].first.second = m;
                break;
            }
        }
        sort (all (tmp), cmp);
        // dbg (tmp);

        bool hasChance = false;
        for (int j = 0; j < k; j++)
        {
            int curVote = tmp[j].first.first, time = tmp[j].first.second, candid = tmp[j].second;
            if (candid == i) 
            {
                hasChance = true;
                break;
            }
        }

        if (hasChance) cout << 2 << " "; 
        else cout << 3 << " ";
    }
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