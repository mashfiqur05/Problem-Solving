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

const int mx = 1e5+123;
int arr[mx];

int main()
{
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        int n;
        ll vasya = 0, patya = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> arr[i];

        int q;
        cin >> q;
        while (q--)
        {
            ll x, tmp = 0;
            cin >> x;
            for (int i = 1; i <= n; i++)
            {
                if (arr[i] == x)
                {
                    tmp++;
                    break;
                }
                else tmp++;
            }
            patya += n - tmp + 1;
            vasya += tmp;
        }

        cout << vasya << ' ' << patya << endl;
    }
    
    return 0;
}