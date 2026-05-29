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
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

void solve() 
{
    int n, k, m;
    cin >> n >> k >> m;
    string s; cin >> s;
    vector<pair<int,int>> food(m);
    for (int i = 0; i < m; i++) cin >> food[i].first >> food[i].second;

    deque<pair<int,int>> snake;
    snake.push_front({1, 1});
    set<pair<int,int>> body;
    body.insert({1, 1});

    int foodIdx = 0;

    auto wrap = [&](int v) {
        return ((v - 1 + n) % n) + 1;
    };

    for (int i = 0; i < k; i++) {
        auto [hx, hy] = snake.front();
        int nx = hx, ny = hy;
        if (s[i] == 'L') ny = wrap(hy - 1);
        else if (s[i] == 'R') ny = wrap(hy + 1);
        else if (s[i] == 'U') nx = wrap(hx - 1);
        else                  nx = wrap(hx + 1);

        bool ateFood = (foodIdx < m && make_pair(nx, ny) == food[foodIdx]);

        pair<int,int> tailCell = snake.back();
        if (!ateFood) {
            body.erase(tailCell);
            snake.pop_back();
        }

        if (body.count({nx, ny})) {
            cout << "DEAD" << endl;
            return;
        }

        snake.push_front({nx, ny});
        body.insert({nx, ny});

        if (ateFood) foodIdx++;
    }

    cout << "ALIVE " << snake.size() << endl;
}

int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}