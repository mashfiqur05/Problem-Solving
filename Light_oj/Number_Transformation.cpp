#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

const int N = 1123;
vector<int> primeFactor[N];
vector<bool> isPrime(N, true);
int dis[N];


void primeGenerator (int n)
{
    int sz = sqrt (n);
    for (int i = 2; i <= sz; i++)
    {
        if (n % i == 0)
        {
            // cout << isPrime[i] << " " << isPrime[n/i];
            if (isPrime[i]) primeFactor[n].push_back (i);
            if (isPrime[n/i] && i != (n/i)) primeFactor[n].push_back (n/i);
        }
    }
}


int bfs (int s, int t)
{
    mem (dis, -1);
    dis[s] = 0;
    queue<int> q;
    q.push (s);
    int cur_dis;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int i = 0; i < primeFactor[u].size(); i++)
        {
            cur_dis = u + primeFactor[u][i];
            if (cur_dis <= t && dis[cur_dis] == -1)
            {
                q.push (cur_dis);
                dis[cur_dis] = dis[u] + 1;
            }
            if (cur_dis == t) return dis[t];
        }
    }

    return dis[t];
}

int32_t main()
{
    Bismillah();

    for (int i = 2; i < sqrt(N); i++)
    {
        if (isPrime[i])
        {
            for (int j = i+i; j < N; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
    
    // for (int i = 0; i < N; i++)
    // {
    //     if (isPrime[i]) cout << i << " ";
    // }
    for (int i = 0; i <= N; i++) primeGenerator(i);

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        int n, m;
        cin >> n >> m;

        int ans = bfs (n, m);
        cout << ans << endl;
    }
    
    return 0;
}