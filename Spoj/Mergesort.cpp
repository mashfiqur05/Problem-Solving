///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

long long n, arr[100005], tmp[100005];

void merge (long long l, long long r)
{
    long long mid = (l + r) / 2;
    long long i1 = l, i2 = mid + 1, j = l;

    while (i1 <= mid && i2 <= r)
    {
        if (arr[i1] <= arr[i2])
        {
            tmp[j] = arr[i1];
            i1++;
        }
        else 
        {
            tmp[j] = arr[i2];
            i2++;
        }
        j++;
    }

    while (i1<=mid) tmp[j++] = arr[i1++];
    while (i2<=r) tmp[j++] = arr[i2++];

    for (long long j = l; j <= r; j++) arr[j] = tmp[j];
}

void mergeSort (long long l, long long r)
{
    if (l == r) return;

    long long mid = (l + r) / 2;
    mergeSort (l, mid);
    mergeSort (mid + 1, r);

    merge (l, r);
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int a;
    n = 0;
    while (cin >> a)
    {
        arr[n] = a;
        n++;
    }

    mergeSort (0, n-1);

    for (long long i = 0; i < n; i++) cout << arr[i] << ' '; cout << endl;

    return 0;
}
