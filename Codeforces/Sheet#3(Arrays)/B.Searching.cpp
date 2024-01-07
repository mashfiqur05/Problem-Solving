/// Given a number N and an array A of N numbers. Determine if the number X exists in array A or not and print its position (0-index).

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

    int t, x;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    cin >> x;
    int temp = 0;

    for (int i = 0; i < t; i++)
    {
        if (arr[i] == x) temp = 1;
        if (temp)
        {
            cout << i;
            break;
        }
    }

    if (!temp) cout << "-1";    

    return 0;
}