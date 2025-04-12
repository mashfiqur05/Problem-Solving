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
const int MX = 2003;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;
vector<pair<int, int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int h, w;
char ar[MX][MX];
pair<int, int> st, finish;
int dis[MX][MX];

int bfs ()
{
    queue<pair<int, int>> q; 
    unordered_map<char, vector<pair<int, int>>> teleport;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (ar[i][j] >= 'a' && ar[i][j] <= 'z')
            {
                teleport[ar[i][j]].push_back({i, j});  
            }
        }
    }

    q.push(st);
    dis[st.first][st.second] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first, y = cur.second;

        if (x == finish.first && y == finish.second) 
        {
            return dis[x][y];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + movements[i].first;
            int ny = y + movements[i].second;
            if (nx >= 0 && ny >= 0 && nx < h && ny < w && ar[nx][ny] != '#' && dis[nx][ny] == -1)
            {
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }

        if (ar[x][y] >= 'a' && ar[x][y] <= 'z')
        {
            char u = ar[x][y];
            for (auto it = teleport[u].begin(); it != teleport[u].end(); ++it)
            {
                int nx = it->first, ny = it->second;
                if (dis[nx][ny] == -1)
                {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
            }

            teleport[u].clear();
        }
    }

    return -1;
}

void testCases (int tt)
{
    mem(dis, -1);
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'S') st = {i, j};
            else if (ar[i][j] == 'G') finish = {i, j};
        }
    }

    cout << bfs() << endl;
}

int main()
{
    fastio();
    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases(tt);
    }
    return 0;
}
