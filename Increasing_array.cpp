#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 2e5+123;
long long arr[mx];

int main()
{
    optimize();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    long long cnt = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i-1])
        {
            cnt += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }

    cout << cnt << endl;

    return 0;
}