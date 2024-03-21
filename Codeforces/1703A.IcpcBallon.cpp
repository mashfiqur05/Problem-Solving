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

set<int> a;

void solve()
{
    int n, ballon = 0;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (a.count(s[i]) == 1)
        {
            ballon++;
        }
        else 
        {
            a.insert (s[i]);
            ballon += 2;
        }
    }

    cout << ballon << endl;
    a.clear();
}

int main()
{
    optimize();

    int t = 1;
    cin >> t;
    while (t--) 
    {
        solve();
    }
    
    return 0;
}