#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 123;
int arr[mx];


void solve()
{
    set<int> s;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) s.insert (i);

    int p, q;
    cin >> p;

    while (p--)
    {
        int a;
        cin >> a;
        s.erase (a);
    }


    cin >> q;
    while (q--)
    {
        int b; 
        cin >> b;
        s.erase (b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s.count (i) == 1)
        {
            ans = 1;
            break;
        }
    }

    if (ans == 0) cout << "I become the guy." << endl;
    else cout << "Oh, my keyboard!" << endl;

}

int main()
{
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        solve();
    }
    
    return 0;
}