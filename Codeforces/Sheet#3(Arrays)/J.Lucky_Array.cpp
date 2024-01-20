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

    int n;
    cin >> n;
    int min = 1e6;
    
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min) min = arr[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == min) cnt++;
    }

    if (cnt % 2 == 1) cout << "Lucky" << endl;
    else cout << "Unlucky" << endl;

    return 0;
}