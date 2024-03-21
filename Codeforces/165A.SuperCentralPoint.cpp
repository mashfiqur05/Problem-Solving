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

const int mx = 213;
int x[mx], y[mx];

int main()
{
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            int right = 0, left = 0, upper = 0, lower = 0;
            for (int j = 1; j <= n; j++)
            {
                if ((x[i] > x[j] && y[i] == y[j])) right++;
                if (x[i] < x[j] && y[i] == y[j]) left++;
                if (x[i] == x[j] && y[i] < y[j]) lower++;
                if (x[i] == x[j] && y[i] > y[j]) upper++;
            }  

            if (right >= 1 && left >= 1 && lower >= 1 && upper >= 1) ans++;
        }

        cout << ans << endl;
    }
    
    return 0;
}