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

const int mx = 123;
int arr[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;

        vector<int> v (n);

        for (int i = 0; i < n; i++) cin >> v[i];

        int cnt5 = count (all (v), 5);
        int cnt0 = count (all (v), 0);
        string s = " ";
        
        if (cnt0 <= 0)
        {
            cout << "-1" << endl;
            return 0;
        }

        while (cnt5)
        {
            if ((cnt5 * 5) % 9 == 0)
            {
                for (int i = 1; i <= cnt5; i++) s += '5';
                break;
            }
            cnt5--;
        }

        if (s.size() == 1) s += '0';
        else for (int i = 1; i <= cnt0; i++) s += '0';

        cout << s << endl;

    }
    
    return 0;
}