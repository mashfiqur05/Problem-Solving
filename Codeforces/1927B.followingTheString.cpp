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

const int mx = 2e5+123;
int arr[mx];


int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    while (testcases--) 
    {
        int n;
        cin >> n;
        
        vector<int> v(n);
        vector<int> cnt(26, 0);
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (cnt[j] == v[i])
                {
                    char ch = j + 'a';
                    ans += ch;
                    cnt[j]++;
                    break;
                }
            }
        }

        cnt.clear();

        cout << ans << endl;
    }
    
    return 0;
}