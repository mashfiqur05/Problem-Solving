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
    string s;
    cin >> s;
    vector<char> tmp;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
        {
            for (int j = tmp.size() - 1; j >= 0; j--)
            {
                if (isupper(tmp[j])) tmp.pop_back();
            }
        }

        else if (s[i] == 'b')
        {   
            for (int j = tmp.size() - 1; j >= 0; j--)
            {
                if (islower(tmp[j])) tmp.pop_back();
            }
        }
        else 
        {
            tmp.push_back(s[i]);
        }
    }

    for (auto u : tmp) cout << u;
    cout << endl;
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