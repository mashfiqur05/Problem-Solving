/// Given a number N and an array A of N numbers. Print all array positions that store a number less than or equal to 10 and the number stored in that position.

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1e5+123;
int arr[mx];

int main()
{
    optimize();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < t; i++)
    {
        if (arr[i] <= 10)
        {
            cout << "A[" << i << "] = " << arr[i] << endl;
        }
    }

    return 0;
}