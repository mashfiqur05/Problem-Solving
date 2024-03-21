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
            cin >> arr[i];
        }
        arr[n+1] = arr[1];
    
        int ans = 1000;
        int index1, index2;
        for (int i = 1; i <= n; i++)
        {
            int tmp = abs(arr[i] - arr[i+1]);
            ans = min (tmp, ans);   
        }
        
        for (int i = 1; i <= n; i++)
        {
            int tmp = abs(arr[i] - arr[i+1]);
            if (ans == tmp) 
            {
                index1 = i;
                index2 = i+1;
            }
        }

        if (index2 == n+1) index2 = 1;
        cout << index1 << ' ' << index2 << endl;    
    }
    
    return 0;
}