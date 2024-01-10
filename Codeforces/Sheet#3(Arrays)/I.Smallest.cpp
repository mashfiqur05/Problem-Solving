#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t, n;
    cin >> t;

    for (int k = 1; k <= t; k++)
    {   
        int result = 1e7;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> arr[i];

        for (int i = 1; i <= n-1; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                int sum = arr[i] + arr[j] + j - i;
                if (sum < result) result = sum;
            }
        }

        cout << result << endl;
    }

    return 0;
}