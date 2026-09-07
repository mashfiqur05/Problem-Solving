///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define endl '\n'
#define ll long long
// #define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int N = 1e7;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

/*
4 5 12 1
8 3 9 2

8 -> 4 -> 2 -> 1
9 -> 3 -> 1

4 1 3 1
4 1 3 1

1+2+3+1 = 7
*/
vector<int> spf(N + 1);
vector<int> primes;

void precompute()
{
    spf[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            primes.push_back(i);
        }

        for (auto p : primes)
        {
            if (p > spf[i] || i * p > N)
                break;

            spf[i * p] = p;
        }
    }
}


// Greatest proper divisor
int getNext(int x)
{
    if (x == 1)
        return 1;

    return x / spf[x];
}


void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (a[i] != b[i])
        {
            // Reduce the larger number
            if (a[i] > b[i])
            {
                a[i] = getNext(a[i]);
            }
            else
            {
                b[i] = getNext(b[i]);
            }

            ans++;
        }
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    precompute();
    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}