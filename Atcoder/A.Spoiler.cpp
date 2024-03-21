#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

//const int mx = 123;
//int arr[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string s;
        cin >> s;
        string ans = " ";
        string rev = " ";

        for (int i= 0; i < s.size(); i++)
        {
            if (s[i] != '|') 
            {
                ans += s[i];
            }
            else break;
        }

        for (int i = s.size()-1; i >= 0; i--)
        {
            if (s[i] != '|') 
            {
                rev += s[i];
            }
            else break;
        }
        
        reverse (all (rev));
        cout << ans << rev;
    }
    
    return 0;
}