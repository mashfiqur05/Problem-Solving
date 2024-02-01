#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    string s;
    cin >> s;

    sort (s.begin(), s.end());

    vector<char> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(s[i]);
    }

    map<char, int> cnt;
    int mx = 0;

    for (auto u : v) 
    {
        cnt[u]++;
        mx = max(mx, cnt[u]);
    }
    
    for (auto u : v)
    {
        if (cnt[u] == mx)
        {
            cout << u << endl;
            break;
        }
    }

    return 0;
}