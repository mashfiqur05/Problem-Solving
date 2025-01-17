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
const int MX = 1123;
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
int n, m;
char g[MX][MX];
int vis[MX][MX];
pair<int, int> a, b;
vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string side = "DURL";
char step[MX][MX];
vector<char> ans;
bool f = 0;

bool isValid (int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

void bfs (pair<int, int> source)
{
    queue<pair<int, int>> q;
    q.push (source);
    vis[source.first][source.second] = 1;
    step[source.first][source.second] = 'X';


    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        int id = 0;

        for (auto m : movements)
        {
            int next_x = x + m.first;
            int next_y = y + m.second;

            if (!isValid (next_x, next_y) || g[next_x][next_y] == '#' || vis[next_x][next_y])
            {
                id++;
                continue;
            }
            
            step[next_x][next_y] = side[id];
            id++;
            // dbg (next_x, next_y, id, step[next_x][next_y]);
            if (next_x == b.first && next_y == b.second)
            {
                // dbg (next_x, next_y, id);
                f = 1;
                return;
            }

            vis[next_x][next_y] = 1;
            q.push ({next_x, next_y});
        }
    }
}


void backtrack(int x, int y)
{
    if (step[x][y] != 'X')
    {
        char ch = step[x][y];
        ans.push_back(ch);
        if (ch == 'U')
            backtrack(x + 1, y);
        else if (ch == 'D')
            backtrack(x - 1, y);
        else if (ch == 'L')
            backtrack(x, y + 1);
        else if (ch == 'R')
            backtrack(x, y - 1);
    }
    // dbg(ans);
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {

        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == 'A') a = {i, j};
                if (g[i][j] == 'B') b = {i, j};
            }
        }

        bfs (a);

        if (f)
        {
            backtrack (b.first, b.second);
            reverse (all (ans));
            cout << "YES" << endl << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) cout << ans[i];
            cout << endl;
            // cout << step[a.first][a.second];
        }
        else cout << "NO\n";

    }


    return 0;
}