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

struct cmp
{
    /* data */
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const 
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};


void testCases (int tt)
{
    vector<int> v;
    vector<bool> f;
    set<pair<int, int>, cmp> polycrap;
    set<int> s;
    int q, cutomerSerial = 1;
    cin >> q;
    while (q--)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int m;
            cin >> m;
            v.push_back (m);
            f.push_back (false);
            s.insert (cutomerSerial);
            polycrap.insert ({m, cutomerSerial});
            cutomerSerial++;
        }
        else if (choice == 2)
        {
            int serial = *s.begin(), money = v[serial-1];
            s.erase (s.begin());
            f[serial-1] = true;
            cout << serial << " ";
        }
        else 
        {
            while (true) {
                auto it = prev(polycrap.end());
                int serial = it->second;
                if (!f[serial - 1]) {
                    polycrap.erase(it);
                    s.erase(serial);
                    f[serial - 1] = true;
                    cout << serial << " ";
                    break;
                } else {
                    polycrap.erase(it);
                }
            }
            
        }
        // dbg (polycrap);
        // dbg (s);
    }
    cout << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}