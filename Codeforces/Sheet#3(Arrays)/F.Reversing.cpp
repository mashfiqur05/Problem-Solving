/// Given a number N and an array A of N numbers. Print the array in a reversed order.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 1123;
int arr[mx];

int main()
{
    optimize();

    /// test case 
    int t;
    cin >> t;

    /// take input of array
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    /// using for loop reverse the array and print it.
    for (int i = 0, j = t -1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 0; i < t; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}