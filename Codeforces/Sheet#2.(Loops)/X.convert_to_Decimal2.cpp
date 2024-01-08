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

    int t;
    cin >> t;

    /// 1.decimal to binary.
    /// 2.count number of ones in the binary representation.
    /// 3.converting that number of one's represent which number of decimal print that number.
    for (int i = 1; i<= t; i++)
    {
        int n;
        cin >> n;
        int cnt = 0;

        while (n != 0)
        {
            int digit = n % 2;
            n /= 2;
            if (digit == 1) cnt++;
        }

        int base = 1;
        int dec_value = 0;
        for(int j = 0; j < cnt; j++)
        {
            dec_value += 1 * base;
            base *= 2; 
        }
        cout << dec_value << endl;
    }

    return 0;
}