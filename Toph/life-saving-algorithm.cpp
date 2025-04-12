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

vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; 

char ar[505][505];
bool vis[505][505];
int n;
bool f = 0;

bool isValid (int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

void bfsForFlood (int x, int y)
{
    queue<pair<int, int>> q;
    q.push ({x, y});
    vis[x][y] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x_cur = cur.first, y_cur = cur.second;

        for (auto val : movements)
        {
            int xchild = x_cur + val.first;
            int ychild = y_cur + val.second;

            if (isValid (xchild, ychild))
            {
                if (ar[xchild][ychild] == '#' && !vis[xchild][ychild])
                {
                    q.push ({xchild, ychild});
                    vis[xchild][ychild] = 1;
                }
            }
        }
        
    }
}

void bfsForDanger (int x, int y)
{
    queue<pair<int, int>> q;
    q.push ({x, y});
    vis[x][y] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x_cur = cur.first, y_cur = cur.second;
        // dbg(cur);

        for (int i = 0; i < 4; i++)
        {
            int xchild = x_cur + movements[i].first;
            int ychild = y_cur + movements[i].second;

            if (isValid (xchild, ychild))
            {
                if (ar[xchild][ychild] == '#')
                {
                    f = 1;
                }
                else if (ar[xchild][ychild] == '*' && !vis[xchild][ychild])
                {
                    q.push ({xchild, ychild});
                    vis[xchild][ychild] = 1;
                }
            }
        }

        for (int i = 4; i < 8; i++)
        {
            int xchild = x_cur + movements[i].first;
            int ychild = y_cur + movements[i].second;

            if (isValid (xchild, ychild))
            {
                if (ar[xchild][ychild] == '#')
                {
                    f = 1;
                }
            }
        }
        
    }
}

void testCases (int tt)
{
    cout << "Case " << tt << ": ";
    mem (vis, 0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ar[i][j];
        }
    }

    int flood = 0, danger = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ar[i][j] == '#' && !vis[i][j])
            {
                flood++;
                bfsForFlood (i, j);
            }
            else if (ar[i][j] == '*' && !vis[i][j])
            {
                f = 0;
                bfsForDanger (i, j);
                if (f) danger++;
                // dbg(i, j, f);
            }
        }
    }

    cout << flood << " " << danger << endl;
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