/// Given a number N and an array A of N numbers. Print the array after doing the following operations:

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

    int t; 
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < t; i++)
    {
        if(arr[i] > 0) cout << "1" << " ";
        else if (arr[i] < 0) cout << "2" << " ";
        else cout << arr[i] << " ";
    }

    return 0;
}