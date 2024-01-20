/// special problem /// implementation ///*800

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

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> arr[i];

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {   
        if (arr[i] >= arr[k] && arr[i] > 0) cnt++;        
    }

    cout << cnt << endl;

    return 0;
}