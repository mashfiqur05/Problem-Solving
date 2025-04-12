///---  In the name of ALLAH    ---///

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

long long tmp[500005], compare = 0;

void merge (long long *arr, long long l, long long r)
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
        compare++;
    }

    while (i1<=mid) {tmp[j++] = arr[i1++]; compare++;}
    while (i2<=r) {tmp[j++] = arr[i2++]; compare++;}

    for (long long j = l; j <= r; j++) arr[j] = tmp[j];
}

void mergeSort (long long *arr, long long l, long long r)
{
    if (l == r) return;

    long long mid = (l + r) / 2;
    mergeSort (arr, l, mid);
    mergeSort (arr, mid + 1, r);

    merge (arr, l, r);
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    long long n;
    cin >> n;   
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort (arr, 0, n-1);

    cout << arr[0];
    for (long long i = 1; i < n; i++) cout << ' ' << arr[i]; cout << endl << compare << endl;

    return 0;
}
