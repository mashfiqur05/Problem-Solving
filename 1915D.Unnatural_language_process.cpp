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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> v;

    for (int i = n-3; s >= 0; i-=2)
    {
        if (s[i] == 'a' || s[i] == 'e')
        {
            x = 3;
        }
        else if (s[i] == 'b' || s[i] == 'c' || s[i] == 'd')
        {
            x = 2;
        }

        while (x--)
        {
            
        }
    }
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