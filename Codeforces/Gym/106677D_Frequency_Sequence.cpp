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
const int N = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

/*
s = 3
3, 1, 1, 2, 1, 3, 2, 2, 3, 3, 4, ...
s = 5
5, 1, 1, 2, 1, 3, 1, 4, 1, 5, 2, 2, 3, 2, 4, 2, 5, 3, 3, 4, 3, 5, 4, 4, 5,   5,   6, 1, 6, 2, 6, 3, 6, 4, 6, 5, 6, 6, 
7, 1, 7, 2, 7, 3, 7, ....

s, 
1, 1, 2, 1, 3, ...1, s
2, 2, 3, 2, 4..., 2, s
.
.
s-1, s-1, s, s
s+1, 1, s+1, 2, s+1, ...., s-1, s+1, s
s+2, 1, s+2, ..... 

5 er case e 
1, 9, 7, 5, 3,1, 10, 10 ,
1, s^2, 2*s, 2s,2s,... 

*/

void solve ()
{
    int s, k; 
    while (cin >> s >> k)
    {
        if (s == 0 && k == 0) break;

        if (k == 1)
        {
            cout << s << endl;
        }
        else if (k <= sq(s)+1)
        {
            int l = 0, r = s;
            while (l < r)
            {
                int mid = (l+r)/2;
                int lastElem = sq(s)+1 - (sq(s-mid));

                if (lastElem >= k) r =mid;
                else
                    l = mid + 1;
            }

            int startingind;
            if (l == 0)
                startingind = 1;
            else
                startingind = sq(s) + 2 - sq(s - l + 1);

            int pos = k - startingind + 1;

            if (l == 0)
                cout << s << endl;
            else if (pos % 2 == 0)
                cout << l << endl;
            else
                cout << l + pos / 2 << endl;
        }
        else 
        {
            int pos = k - sq(s)-2;
            int block = pos / (2*s), ind = pos % (2*s), base = s+1+block;

            if (ind % 2 == 0) cout << base << endl;
            else cout << (ind+1)/2 << endl;
        }
    }
}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}