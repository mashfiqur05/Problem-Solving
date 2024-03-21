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
int arr[mx][mx];
int brr[mx][mx];

int main()
{
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++) 
            {
                int a;
                cin >> a;
                a = a % 2;
                arr[i][j] = a;
            }
        }

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++) brr[i][j] = 1;
        }

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (arr[i][j] == 1)
                {
                    if (brr[i][j] == 0) brr[i][j] = 1;
                    else brr[i][j] = 0;

                    if (brr[i+1][j] == 0) brr[i+1][j] = 1;
                    else brr[i+1][j] = 0;

                    if (brr[i-1][j] == 0) brr[i-1][j] = 1;
                    else brr[i-1][j] = 0;

                    if (brr[i][j+1] == 0) brr[i][j+1] = 1;
                    else brr[i][j+1] = 0;

                    if (brr[i][j-1] == 0) brr[i][j-1] = 1;
                    else brr[i][j-1] = 0;
                }
            }
        }

        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++) cout << brr[i][j];
            cout << endl;
        }
    }
    
    return 0;
}