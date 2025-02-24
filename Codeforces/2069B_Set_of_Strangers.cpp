#include <bits/stdc++.h>
using namespace std;

#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define MX 707

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


int v[MX][MX];

void testCases()
{
    int n, m;
    cin >> n >> m;
    unordered_set<int> unique;
    map<int, int> cost;  

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            unique.insert(v[i][j]);
            cost[v[i][j]] = 1;  
        }
    }

    if (unique.size() == 1)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int c = v[i][j];

            if ((i + 1 < n && v[i][j] == v[i + 1][j]) ||
                (j + 1 < m && v[i][j] == v[i][j + 1]))
            {
                cost[c] = 2; 
            }
        }
    }

    ll S = 0;
    int best = 0;
    for (auto it = cost.begin(); it != cost.end(); ++it)
    {
        int c = it->first;   
        int cost = it->second; 
        S += cost;
        best = max(best, cost);
    }

    cout << (S - best) << endl;
}

int32_t main()
{
    fastio();
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        testCases();
    }
    return 0;
}
