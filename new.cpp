#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t; 
    cin >> t; 

    while (t--)
    {
        string s;
        getline(cin, s);

        string temp;
        vector<string> v;
        for (auto u : s)
        {
            if (isspace(u)) 
            {
                v.push-back(temp);
                temp.clear();
            } 
            else s += u;
        }

        temp.push_back(temp);

        map<string, int> cnt;
        int mxfreq = 0;

        for ( auto u : v)
        {
            cnt[u]++;
            mxfreq = max (mxfreq, cnt[u]);
        }
        
        string ans;
        for (auto u : v) 
        {
            if (mxfreq == cnt[u])
            {
                ans = u;
                break;
            }
        }

        cout << ans << " " << mxfreq << endl;

    }

    return 0;
}