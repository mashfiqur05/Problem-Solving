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
int arr[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    while (testcases--) 
    {
        string s;
        cin >> s;

        int acnt = 0, bcnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A') acnt++;
            else bcnt++;
        }

        if (acnt > bcnt) cout << 'A' << endl;
        else cout << 'B' << endl;
    }
    
    return 0;
}