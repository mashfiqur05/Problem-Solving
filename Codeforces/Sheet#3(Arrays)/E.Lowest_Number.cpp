/// Given a number N and an array A of N numbers. Print the lowest number and its position.

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
    int index = 0;
    int lowest = 1e5;

    for (int i = 1; i <= t; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= t; i++)
    {
        if (arr[i] < lowest) 
        {
            lowest = arr[i];
            index = i;
        }
    }

    cout << lowest << " " << index;

    return 0;
}