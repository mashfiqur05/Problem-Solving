#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1e5+123;
int arr[mx];

int main()
{
    optimize();

    /// take test case input
    int t;
    cin >> t;
    
    /// take array input
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    /// check pallindrome or not using for and if loop
    int pallin = 1;
    for (int i= 0, j = t-1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        if (arr[i] != arr[j])
        {
            cout << "NO";
            pallin =0;
            break;
        }
    }
    if (pallin) cout << "YES";

    return 0;
}