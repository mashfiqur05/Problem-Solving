#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t, n;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        int sum1 = 0, sum2 = 0;
        int num1 = n / 1000;
        int num2 = n % 1000;
        while (num1 != 0)
        {
            int temp = num1 % 10;
            sum1 += temp;
            num1 /= 10;         
        }

        while (num2 != 0)
        {
            int tmp = num2 % 10;
            sum2 += tmp;
            num2 /= 10;
        }

        if (sum1 == sum2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}