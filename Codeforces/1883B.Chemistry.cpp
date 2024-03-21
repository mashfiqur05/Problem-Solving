#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 123;

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    while (testcases--) 
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            cnt[ch - 'a']++;
        }
        
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] % 2 == 1) res++;
        }
        
        cnt.clear();

        if ((res - 1) <= k) cout << "YES" << endl;
        else if (n == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}