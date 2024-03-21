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

const int mx = 13;
char arr[mx][mx];

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    while (testcases--) 
    {   
        
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) cin >> arr[i][j];
        }
        bool ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if  (arr[i][j] == '1') 
                //cout <<  i << j << endl;
                {
                    if ((arr[i][j+1] == '1') && (arr[i+1][j] == '1') && (arr[i+1][j+1] == '1')) 
                    {
                        ans = 1;
                    }
                    goto end;
                }
            }
        }
        end:
        if (ans == 1) cout << "SQUARE" << endl;
        else cout << "TRIANGLE" << endl;
    
    }
    
    return 0;
}