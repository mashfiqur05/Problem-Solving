///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

// #define endl '\n'
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

int query (int x, int y)
{
    cout << "? " << x << " " << y << endl;
    int q;
    cin >> q;
    return q;
}

void testCases (int tt)
{
    vector<int> v = {4, 8, 15, 16, 23, 42};

    int a = query (1, 2);
    int b = query (2, 3);
    int c = query (4, 5);
    int d = query (5, 6);

    vector<int> ans(6);
    int pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == j) continue;
            if (v[i] * v[j] == a) 
            {
                pos1 = v[i];
                pos2 = v[j];
            }

            if (v[i] * v[j] == b) 
            {
                pos3 = v[i];
                pos4 = v[j];
            }

            if (v[i] * v[j] == c) 
            {
                pos5 = v[i];
                pos6 = v[j];
            }
            if (v[i] * v[j] == d) 
            {
                pos7 = v[i];
                pos8 = v[j];
            }
        }
    }

    if (pos1 == pos3 || pos1 == pos4)
    {
        ans[0] = pos2, ans[1] = pos1, ans[2] = pos3 + pos4 - pos1;
    }
    else ans[0] = pos1, ans[1] = pos2, ans[2] = pos3 + pos4 - pos2;

    if (pos5 == pos7 || pos5 == pos8)
    {
        ans[3] = pos6, ans[4] = pos5, ans[5] = pos7 + pos8 - pos5;
    }
    else ans[3] = pos5, ans[4] = pos6, ans[5] = pos7 + pos8 - pos6;

    cout << "! ";
    for (auto u : ans) cout << u << " "; cout << endl;
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